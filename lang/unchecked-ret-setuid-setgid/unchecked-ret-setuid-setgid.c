int main() {
    // ok: unchecked-ret-setuid-setgid
    int ret = setuid(0);
    if (ret == 0) {
        printf("ok");
    }
    
    // ok: unchecked-ret-setuid-setgid
    if (seteuid(0)) {
        printf("ok");
    }

    // ok: unchecked-ret-setuid-setgid
    int a = setegid(0) == 0 ? 1 : 2;

    // ruleid: unchecked-ret-setuid-setgid
    setgid(0);

    return 0;
}