#include <stdio.h>

int good_code1(pam_handle_t *pamh) {
    if (pam_authenticate(pamh, PAM_DISALLOW_NULL_AUTHTOK) != PAM_SUCCESS) { // Noncompliant - missing pam_acct_mgmt
        return -1;
    }
    if (pam_acct_mgmt(pamh, 0) != PAM_SUCCESS) {
        return -1;
    }

    // ok: missing-account-validity-check-pam
    pam_getenv(pamh, "ENV");
    return 0;
}

int bad_code1(pam_handle_t *pamh) {
    if (pam_authenticate(pamh, PAM_DISALLOW_NULL_AUTHTOK) != PAM_SUCCESS) { // Noncompliant - missing pam_acct_mgmt
        return -1;
    }
    
    // ruleid: missing-account-validity-check-pam
    pam_getenv(pamh, "ENV");
    return 0;
}

int good_code2(pam_handle_t *pamh) {
    int a = pam_authenticate(pamh, PAM_DISALLOW_NULL_AUTHTOK);
    if (a != PAM_SUCCESS) { // Noncompliant - missing pam_acct_mgmt
        return -1;
    }
    int b = pam_acct_mgmt(pamh, 0);
    if (pam_acct_mgmt(pamh, 0) != PAM_SUCCESS) {
        return -1;
    }

    // ok: missing-account-validity-check-pam
    pam_getenv(pamh, "ENV");
    return 0;
}

int bad_code2(pam_handle_t *pamh) {
    int a = pam_authenticate(pamh, PAM_DISALLOW_NULL_AUTHTOK);
    if (a != PAM_SUCCESS) { // Noncompliant - missing pam_acct_mgmt
        return -1;
    }
    
    // ruleid: missing-account-validity-check-pam
    pam_getenv(pamh, "ENV");
    return 0;
}
