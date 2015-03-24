
#include "evaluator.h"
#include "ast.h"
#include "assignment.h"
#include "misc.h"


/* Se define recursivamente si una formula proposicional parseada es cierta */
int eval(ASTNode *f, Asgmnt *a) {

    Asgmnt *a_result = calloc(1, sizeof(struct Asgmnt));
    
    switch(f->type) {
        case AND: 
            printf("FTYPE is AND: %d \n", f->type);
            eval(f->l_succ, a) * eval(f->r_succ, a);
            break;
        case OR:
            printf("FTYPE is OR: %d \n", f->type);
            eval(f->l_succ, a) + eval(f->r_succ, a);
            break;
        case NOT:
            printf("FTYPE is AND: %d \n", f->type);
            (1 + eval(f->l_succ, a)) % 2;
            (1 + eval(f->r_succ, a)) % 2;
            break;
        case IFF:
            printf("FTYPE is IFF: %d \n", f->type);
            (int)(eval(f->l_succ, a) == eval(f->r_succ, a));
            break;
        case IMPL:
            printf("FTYPE is IMPL: %d \n", f->type);
            break;
        case PROP:
            printf("FTYPE is PROP: %d \n", f->type);
            ASSIGNMENT_FIND(a, &f->id, a_result);
            break;
        default:
            printf("DEFAULT! :[%d] \n", f->type);
    }
    return a_result->value;
}
