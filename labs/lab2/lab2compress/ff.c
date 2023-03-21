#include "hed.h"

char *file_read(char file[]) {

    long len;
    FILE *fl = fopen(file, "rb");

    if (fl == NULL)
        return NULL;

    fseek(fl, 0, SEEK_END);
    len = ftell(fl);
    fseek(fl, 0, SEEK_SET);
    char *buffer = calloc(len, 1);

    fread(buffer, 1, len, fl);
    fclose(fl);

    return buffer;
}

void replace_words(Node *head, str *split_text, char data[]) {
    Node *a = head;
    while (a) {
        int max = 0;
        char *word;
        Node *b = head;
        while (b) {
            int profit = count_profit(a, b);
            if (profit > max) {
                max = profit;
                word = b->word;
            }
            b = b->next;
        }
        if (max > 0) {
            mark_used(head, a->word);
            mark_used(head, word);

            if (strlen(word) == 0 || strlen(a->word) == 0) continue;
            swap_words(split_text, a->word, word);
            FILE *fp = fopen(data, "ab");
            if (fp == NULL)
                exit(0);
            fputs(a->word, fp);
            fputs(" ", fp);
            fputs(word, fp);
            fputs("\n", fp);
            fclose(fp);
        }
        a = a->next;
    }
}

int check(Node *head, char *word) {
    while (head) {
        if (strcmp(head->word, word) == 0)
            return 1;
        head = head->next;
    }
    return 0;
}

void swap_words(str *text, char *word1, char *word2) {
    for (int i = 0; i < text->len; i++) {
        if (strcmp(text->str[i], word1) == 0) {
            text->str[i] = word2;
        } else if (strcmp(text->str[i], word2) == 0) {
            text->str[i] = word1;
        }
    }
}

void push_back(Node **head, char *word, int count) {
    Node *last = getLast(*head);
    Node *tmp = (Node *) malloc(sizeof(Node));
    tmp->word = word;
    tmp->count = count;
    tmp->len = strlen(word);
    tmp->used = 0;
    tmp->next = NULL;
    if (*head == NULL) {
        *head = tmp;
        return;
    }
    last->next = tmp;
}

str *split(char *input, char *delimiter) {

    str *str = malloc(sizeof(str));
    str->str = NULL;
    str->len = 0;

    char *token = multi_tok(input, delimiter);

    while (token != NULL) {
        str->str = realloc(str->str, (str->len + 1) * sizeof(char *));
        str->str[str->len++] = token;
        token = multi_tok(NULL, delimiter);
    }
    return str;
}

Node *getLast(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}

void merge(Node *a, Node *b, Node **c) {
    Node tmp;
    *c = NULL;
    if (a == NULL) {
        *c = b;
        return;
    }
    if (b == NULL) {
        *c = a;
        return;
    }
    if (a->count * a->len > b->count * b->len) {
        *c = a;
        a = a->next;
    } else {
        *c = b;
        b = b->next;
    }
    tmp.next = *c;
    while (a && b) {
        if (a->count * a->len > b->count * b->len) {
            (*c)->next = a;
            a = a->next;
        } else {
            (*c)->next = b;
            b = b->next;
        }
        (*c) = (*c)->next;
    }
    if (a) {
        while (a) {
            (*c)->next = a;
            (*c) = (*c)->next;
            a = a->next;
        }
    }
    if (b) {
        while (b) {
            (*c)->next = b;
            (*c) = (*c)->next;
            b = b->next;
        }
    }
    *c = tmp.next;
}

void split_linked_list(Node *src, Node **low, Node **high) {
    Node *fast = NULL;
    Node *slow = NULL;

    if (src == NULL || src->next == NULL) {
        (*low) = src;
        (*high) = NULL;
        return;
    }
    slow = src;
    fast = src->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    (*low) = src;
    (*high) = slow->next;
    slow->next = NULL;
}

void merge_sort(Node **head) {
    Node *low = NULL;
    Node *high = NULL;
    if ((*head == NULL) || ((*head)->next == NULL)) {
        return;
    }
    split_linked_list(*head, &low, &high);
    merge_sort(&low);
    merge_sort(&high);
    merge(low, high, head);
}

int count_profit(Node *a, Node *b) {
    if (a->count <= b->count) return -0;
    else if (a->used || b->used) return -1;
    else
        return (a->count * a->len + b->count * b->len) - (a->count * b->len + b->count * a->len) -
               (b->len + a->len + 2);
}

void mark_used(Node *head, char *word) {
    while (head) {
        if (strcmp(head->word, word) == 0) {
            head->used = 1;
            return;
        }
        head = head->next;
    }
}

void count_repeats(str *split_text, Node **head) {

    for (int i = 0; i < split_text->len; i++) {

        if (check(*head, split_text->str[i]))
            continue;
        if (strstr(split_text->str[i], "\n") != NULL)
            continue;
        int cnt = 0;
        for (int j = 0; j < split_text->len; j++) {
            if (strcmp(split_text->str[i], split_text->str[j]) == 0) {
                cnt++;
            }
        }
        push_back(&(*head), split_text->str[i], cnt);
    }
    merge_sort(&(*head));
}

char *multi_tok(char *input, char *delimiter) {
    static char *string;
    if (input != NULL)
        string = input;
    if (string == NULL)
        return string;
    char *end = strstr(string, delimiter);
    if (end == NULL) {
        char *temp = string;
        string = NULL;
        return temp;
    }
    char *temp = string;
    *end = '\0';
    string = end + strlen(delimiter);
    return temp;
}
