
char* strstr_own(char *str, char *substr){
    while(*str){ // for each cipher of str
	    char *Begin = str;
	    char *pattern = substr;

	    // if first character of sub string match, check for whole string
	    while(*str && *pattern && *str == *pattern){
		      str++;
		      pattern++;
	    }

	    // if complete substring match, return starting address 
	    if(!*pattern)
	    	  return Begin; // return str
	    str = Begin + 1;	// increment main string 
	}
	return 0;
}