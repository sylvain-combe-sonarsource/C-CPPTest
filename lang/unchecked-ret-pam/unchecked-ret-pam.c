#include <security/pam_appl.h>

bool check(int a) {
    return a == PAM_SUCCESS;
}

int main () {
    pam_handler_t * pamh;
    // ok: unchecked-ret-pam
    int ret1 = pam_authenticate(pamh, PAM_DISALLOW_NULL_AUTHTOK);

    if (ret1 == PAM_SUCCESS) {
        printf("ok");
    }

    // ruleid: unchecked-ret-pam
    int ret2 = pam_authenticate(pamh, PAM_DISALLOW_NULL_AUTHTOK);
    pam_getenv(pamh, "ENV");

    // ok: unchecked-ret-pam
    int ret3 = pam_acct_mgmt(pamh, 0);
    bool ok = check(ret3);
    if (ok) {
        printf("ok");
    }

    // ok: unchecked-ret-pam
    if (pam_authenticate(pamh, PAM_DISALLOW_NULL_AUTHTOK) == PAM_SUCCESS) {
        printf("ok");
    }

    return 0;
}