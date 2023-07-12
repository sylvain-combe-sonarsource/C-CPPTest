#include <stdbool.h>
#include <securitybaseapi.h>
#include <heapapi.h>

// False bDaclPresent
int main() {
    SECURITY_DESCRIPTOR sd={0,};
    InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
    // ok: null-dacl-SetSecurityDescriptorDacl
    SetSecurityDescriptorDacl(&sd, false, NULL, false);
}

// Non-null ACL passed in
int main() {
    SECURITY_DESCRIPTOR sd={0,};
    InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
    PACL acl = HeapAlloc(GetProcessHeap(), 0, sizeof(ACL));
    InitializeAcl(acl, sizeof(ACL), ACL_REVISION);
    // ok: null-dacl-SetSecurityDescriptorDacl
    SetSecurityDescriptorDacl(&sd, true, acl, false);
}

// Standard use of SetSecurityDescriptorDacl with NULL pDacl
int main() {
    SECURITY_DESCRIPTOR sd={0,};
    InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
    // ruleid: null-dacl-SetSecurityDescriptorDacl
    SetSecurityDescriptorDacl(&sd, true, NULL, false);
}

// Use of variable in 2nd and/or 3rd parameter
// Currently false negative
int main() {
    SECURITY_DESCRIPTOR sd={0,};
    InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
    bool isPresent = true;
    // ruleid: null-dacl-SetSecurityDescriptorDacl
    SetSecurityDescriptorDacl(&sd, isPresent, NULL, false);
    PACL dacl = NULL;
    // todoruleid: null-dacl-SetSecurityDescriptorDacl
    SetSecurityDescriptorDacl(&sd, true, dacl, false);
    // todoruleid: null-dacl-SetSecurityDescriptorDacl
    SetSecurityDescriptorDacl(&sd, isPresent, dacl, false);
}