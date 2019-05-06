char* mystrdup(char* s) {
	size_t length = strlen(s); // Length of the original string

	// Allocate a block of memory big enough to hold all the characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(length + 1);
	if (newstr) { // If allocation succeeded, copy into it
		strcpy(newstr, s);
	}
	return newstr;
}
