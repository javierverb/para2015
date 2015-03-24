
#include "evaluator.h"
#include "ast.h"
#include "assignment.h"
#include "misc.h"


/* Se define recursivamente si una formula proposicional parseada es cierta */
int eval(ASTNode *f, Asgmnt *a) {

    Asgmnt *a_result = calloc(1, sizeof(struct Asgmnt));
    
    switch(f->type) {
        case AND: 
            eval(f->l_succ, a) * eval(f->r_succ, a);
            break;
        case OR:
            eval(f->l_succ, a) - eval(f->r_succ, a);
            break;
        case NOT:
            (1 + eval(f->l_succ, a)) % 2;
            (1 + eval(f->r_succ, a)) % 2;
            break;
        case IFF:
            (int)(eval(f->l_succ, a) == eval(f->r_succ, a));
            break;
        case IMPL:
            break;
        case PROP:
            ASSIGNMENT_FIND(a, &f->id, a_result);
            break;
    }
    return a_result->value;
}
