#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 10000

// Structure représentant une liste de mots
typedef struct {
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    int num_words;
} WordList;

// Initialiser une liste de mots
void initializeWordList(WordList *word_list) {
    word_list->num_words = 0;
}

// Ajouter un mot à la liste
void addWord(WordList *word_list, const char *word) {
    if (word_list->num_words < MAX_NUM_WORDS) {
        strcpy(word_list->words[word_list->num_words], word);
        word_list->num_words++;
    }
}

// Afficher les mots filtrés par une lettre spécifique
void filterByLetter(const WordList *word_list, char letter) {
    int i;
    for (i = 0; i < word_list->num_words; i++) {
        if (strchr(word_list->words[i], letter) != NULL) {
            printf("%s\n", word_list->words[i]);
        }
    }
}

// Afficher les mots filtrés par une liste de lettres spécifiques
void filterByLetters(const WordList *word_list, const char *letters) {
    int i, j, contains_all;
    for (i = 0; i < word_list->num_words; i++) {
        contains_all = 1;
        for (j = 0; j < strlen(letters); j++) {
            if (strchr(word_list->words[i], letters[j]) == NULL) {
                contains_all = 0;
                break;
            }
        }
        if (contains_all) {
            printf("%s\n", word_list->words[i]);
        }
    }
}

// Exclure les mots contenant certaines lettres
void excludeLetters(const WordList *word_list, const char *letters) {
    int i, j, contains_any;
    for (i = 0; i < word_list->num_words; i++) {
        contains_any = 0;
        for (j = 0; j < strlen(letters); j++) {
            if (strchr(word_list->words[i], letters[j]) != NULL) {
                contains_any = 1;
                break;
            }
        }
        if (!contains_any) {
            printf("%s\n", word_list->words[i]);
        }
    }
}

// Afficher les mots filtrés par une sous-chaîne spécifique
void filterBySubstring(const WordList *word_list, const char *substring) {
    int i;
    for (i = 0; i < word_list->num_words; i++) {
        if (strstr(word_list->words[i], substring) != NULL) {
            printf("%s\n", word_list->words[i]);
        }
    }
}

int main() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    WordList word_list;
    initializeWordList(&word_list);

    // Ouvrir le fichier
    file = fopen("bdd_wordle.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    // Lire les mots à partir du fichier et les ajouter à la liste
    while (fscanf(file, "%s", word) != EOF) {
        addWord(&word_list, word);
    }

    // Fermer le fichier
    fclose(file);

    // Filtrer les mots selon les critères spécifiés
    filterByLetter(&word_list, 'a');
    filterByLetters(&word_list, "ab");
    excludeLetters(&word_list, "e");
    filterBySubstring(&word_list, "ing");

    return 0;
}

