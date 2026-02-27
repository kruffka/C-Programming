#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Movie {
    int id;
    char title[100];
    int duration;
    double rating;
} Movie;

typedef struct Node {
    Movie *movie;
    struct Node *prev;
    struct Node *next;
} Node;

typedef struct WatchHistory {
    Node *head;
    Node *tail;
    Node *current;
    int size;
} WatchHistory;

Movie *createMovie(int id, const char *title, int duration, double rating) {
    Movie *movie = (Movie *)malloc(sizeof(Movie));
    movie->id = id;
    strcpy(movie->title, title);
    movie->duration = duration;
    movie->rating = rating;
    return movie;
}

Node *createNode(Movie *movie) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->movie = movie;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

WatchHistory *createWatchHistory() {
    WatchHistory *history = (WatchHistory *)malloc(sizeof(WatchHistory));
    history->head = NULL;
    history->tail = NULL;
    history->current = NULL;
    history->size = 0;
    return history;
}

void addToHistory(WatchHistory *history, Movie *movie) {
    Node *newNode = createNode(movie);
    
    if (history->head == NULL) {
        history->head = newNode;
        history->tail = newNode;
        history->current = newNode;
    } else {
        newNode->prev = history->tail;
        history->tail->next = newNode;
        history->tail = newNode;
    }
    history->size++;
}

int removeFromHistory(WatchHistory *history, int movieId) {
    Node *current = history->head;
    
    while (current != NULL) {
        if (current->movie->id == movieId) {
            if (current == history->head && current == history->tail) {
                history->head = NULL;
                history->tail = NULL;
                history->current = NULL;
            }
            else if (current == history->head) {
                history->head = current->next;
                history->head->prev = NULL;
            }
            else if (current == history->tail) {
                history->tail = current->prev;
                history->tail->next = NULL;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            
            free(current->movie);
            free(current);
            history->size--;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void nextMovie(WatchHistory *history) {
    if (history->current != NULL && history->current->next != NULL) {
        history->current = history->current->next;
        printf("Now watching: %s\n", history->current->movie->title);
    } else {
        printf("This is the last movie in history\n");
    }
}

void previousMovie(WatchHistory *history) {
    if (history->current != NULL && history->current->prev != NULL) {
        history->current = history->current->prev;
        printf("Now watching: %s\n", history->current->movie->title);
    } else {
        printf("This is the first movie in history\n");
    }
}

void jumpToMovie(WatchHistory *history, int movieId) {
    Node *current = history->head;
    
    while (current != NULL) {
        if (current->movie->id == movieId) {
            history->current = current;
            printf("Jumping to: %s\n", current->movie->title);
            return;
        }
        current = current->next;
    }
    printf("Movie with ID %d not found in history\n", movieId);
}

void displayHistory(WatchHistory *history) {
    if (history->head == NULL) {
        printf("Watch history is empty\n");
        return;
    }
    
    printf("\n=== WATCH HISTORY ===\n");
    Node *current = history->head;
    int position = 1;
    
    while (current != NULL) {
        printf("%d. ", position++);
        if (current == history->current) {
            printf("▶ ");
        }
        printf("[ID: %d] %s (%d min) - Rating: %.1f\n", 
               current->movie->id, 
               current->movie->title,
               current->movie->duration,
               current->movie->rating);
        current = current->next;
    }
    printf("====================\n\n");
}

void freeHistory(WatchHistory *history) {
    Node *current = history->head;
    Node *next;
    
    while (current != NULL) {
        next = current->next;
        free(current->movie);
        free(current);
        current = next;
    }
    
    free(history);
}

int main() {
    WatchHistory *myHistory = createWatchHistory();
    
    // ИИ накинула киношек
    addToHistory(myHistory, createMovie(1, "Inception", 148, 8.8));
    addToHistory(myHistory, createMovie(2, "The Matrix", 136, 8.7));
    addToHistory(myHistory, createMovie(3, "Fight Club", 139, 8.9));
    addToHistory(myHistory, createMovie(4, "Interstellar", 169, 8.6));
    addToHistory(myHistory, createMovie(5, "Oppenheimer", 180, 8.5));
    addToHistory(myHistory, createMovie(6, "Barbie", 114, 7.0));
    addToHistory(myHistory, createMovie(7, "Poor Things", 141, 8.4));
    addToHistory(myHistory, createMovie(8, "Dune: Part Two", 166, 9.0));
    addToHistory(myHistory, createMovie(9, "The Batman", 176, 7.8));
    addToHistory(myHistory, createMovie(10, "Everything Everywhere All at Once", 139, 8.7));
    addToHistory(myHistory, createMovie(11, "Top Gun: Maverick", 130, 8.3));

    printf("Initial watch history:\n");
    displayHistory(myHistory);
    
    printf("Next:\n");
    nextMovie(myHistory);
    printf("Next:\n");
    nextMovie(myHistory);
    printf("Prev:\n");
    previousMovie(myHistory);
    printf("\n");
    
    displayHistory(myHistory);
    
    jumpToMovie(myHistory, 5);
    printf("\n");
    
    displayHistory(myHistory);
    
    printf("Removing 'The Matrix' (ID: 2)\n");
    removeFromHistory(myHistory, 2);
    
    displayHistory(myHistory);
    
    freeHistory(myHistory);
    
    return 0;
}