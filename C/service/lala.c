#include <ldap.h>
#include <stdio.h>

#define HOSTNAME "ldap://10.1.108.54:389"
#define ROOT_DN "cn=Manager,dc=whgd,dc=com"
#define FIND_DN "dc=whgd,dc=com"

void main()
{
    LDAP * ld = NULL;
    int ldresult, version;
    int rc;

    ldresult = ldap_initialize(&ld, "ldap://10.1.108.54:389");
    if (LDAP_SUCCESS != ldresult)
    {
        perror("ldap_initialize");
        return;
    }

    version = LDAP_VERSION3;
    ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &version);

    rc = ldap_simple_bind_s(ld, ROOT_DN, "secret");
    if (LDAP_SUCCESS != rc)
    {
        fprintf(stderr, "ldap_simple_bind_s: %s\n", ldap_err2string(rc));
        return;
    }
#if 0
    while (1)
    {
        
    }
    return;
#endif
}
