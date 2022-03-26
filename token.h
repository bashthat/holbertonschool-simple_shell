#ifndef SHELLZ_H
#define SHELLZ_H

struct token_s
{
	struct srouce_s *src; //the input
	int text_len; //token length
	char *text; //token text
};

extern struct token_s eof_token;

struct token_s *tokenize(struct source_s *src);
void free_token(struct token_s *tok);

#endif
