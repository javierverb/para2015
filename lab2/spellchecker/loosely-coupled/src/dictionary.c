#include "dictionary.h"

struct Dictionary {
    /* Completar aqui */
    char** dict_main;
    char** dict_ignored;
    int main_size
    int ignored_size;
};

void dict_load(*char filename);

void dict_save(char* fname);

void dict_add(char* word);

dict_contains();

dict_s dict_new(void){
	
	dict_s new_dict = NULL;
	new_dict = calloc(1,sizeof(struct Dictionary));

	new_dict->dict_main = NULL;
	new_dict->dict_ignored = NULL;
	new_dict->main_size = 10;
	new_dict->ignored_size = 0;

	return new_dict;

}

dict_s dict_destroy(dict_s d){

	int i,j = 0;
	/* liberamos todo el dict_main */
	for(i;i<d->main_size;i++){
		free(d->dict_main[i])
		d->dict_main[i] = NULL;
		i++;
	}
	/* liberamos todo el dict_ignored */
	for(j;j<d->ignored_size;j++){
		free(d->dict_ignored[j])
		d->dict_ignored[i] = NULL;
		j++;
	}
	
	free(dict_main);
	dict_main = NULL;

	free(dict_ignored);
	dict_ignored = NULL;
	
	free(d);
	d = NULL;

	return d;
}

ignored_add();
