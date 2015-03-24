
#include "evaluator.h"
#include "ast.h"
#include "assignment.h"
#include "misc.h"


/* Se define recursivamente si una formula proposicional parseada es cierta */
int eval(ASTNode *f, Asgmnt *a) {

    if (f != NULL) {
        Asgmnt *a_result = NULL;
        a_result = calloc(1, sizeof(struct Asgmnt));
        
        switch(f->type) {
            case AND:
                a_result->value = eval(f->l_succ, a) * eval(f->r_succ, a);
                break;
            case OR:
                a_result->value = (int)(eval(f->l_succ, a) + eval(f->r_succ, a)) > 0;
                break;
            case NOT:
                a_result->value = (1 + eval(f->l_succ, a)) % 2;
                a_result->value = (1 + eval(f->r_succ, a)) % 2;
                break;
            case IFF:
                a_result->value = (int)(eval(f->l_succ, a) == eval(f->r_succ, a));
                break;
            case IMPL:
                a_result->value = 0; // mentira, aplicar lógica del implica
                break;
            case PROP:
                // ASSIGNMENT_PRINT(a);
                ASSIGNMENT_FIND(a, &f->id, a_result);
                break;
            default:
                printf("Ningun caso base detectado\n");
                return -1;
        }
        return a_result->value;
    }
}
