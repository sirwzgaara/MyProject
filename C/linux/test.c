#include <stdio.h>
#include <ldap.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define HOSTNAME "ldap://10.1.108.52:389"
#define ROOT_DN "cn=Manager,dc=example,dc=com"

int ldap_rebind(LDAP * ld, LDAP_CONST char * url, ber_tag_t request, ber_int_t msgid, void *parms)
{
    while (1)
    {
        sleep(1);
        fprintf(stderr, "in ldap_rebind\n");
    }
    return 1;
}

void main()
{
    LDAP * ld = NULL;
    int rc, version, n;
    char buf[1024];

    rc = ldap_initialize(&ld, HOSTNAME);
    if (rc != LDAP_SUCCESS)
    {
        perror("ldap_initialize");
        return;
    }
    
    version = LDAP_VERSION3;
    ldap_set_option(ld, LDAP_OPT_PROTOCOL_VERSION, &version);

    rc = ldap_set_option(ld, LDAP_OPT_REFERRALS, LDAP_OPT_ON);
    if (rc != LDAP_SUCCESS)
    {
        fprintf(stderr, "set opt referrals: %s\n", ldap_err2string(rc));
        return;
    }

    rc = ldap_set_rebind_proc(ld, ldap_rebind, NULL);
    if (rc != LDAP_SUCCESS)
    {
        fprintf(stderr, "ldap_set_rebind_proc: %s\n", ldap_err2string(rc));
        return;
    }

    rc = ldap_simple_bind_s(ld, ROOT_DN, "secret");
    if (rc != LDAP_SUCCESS)
    {
        fprintf(stderr, "ldap_simple_bind_s: %s\n", ldap_err2string(rc));
        return;
    }

    n = read((int)*(int *)&ld, buf, 1024);
    fprintf(stderr, "n = %d\n");

    while (1)
    {
        sleep(1);
        n = read((int)*(int *)&ld, buf, 1024);
        fprintf(stderr, "n = %d\n");
    }
}
