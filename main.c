#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TOTAL_SIZE 20

typedef struct{
	int totalFeatures;
	int totalValue;
} Combination;

typedef struct{
	char name[TOTAL_SIZE];
	int value;
	int totalFeatures;
	int *features;
} Movie;



void addCombination(Movie* movieList, int totalMovies, Combination* combination, char** combinationsMovies, int size, int* totalCombination){
    int value = 0;
    int features[size*TOTAL_SIZE];
    int totalFeatures = 0;

    for(int a = 0; a < size; a++){
        for(int b = 0; b < totalMovies; b++){
            bool verify = strcmp(combinationsMovies[a], movieList[b].name);
            if(!verify){
                value += movieList[b].value;
                for(int c = 0; c < movieList[b].totalFeatures; c++){
                    bool existFeature = false;
                    for(int counter = 0; counter < totalFeatures; counter++)
                        if(features[counter] == movieList[b].features[c]) {
                            existFeature = true;
                            break;
                        }
                    
                    if(!existFeature) features[totalFeatures++] = movieList[b].features[c];
                }
            }
        }
    }
    
    combination[*totalCombination].totalValue = value;
    combination[*totalCombination].totalFeatures = totalFeatures;
    (*totalCombination)++;
}

void auxCreateCombination(Movie *movies, int totalMovies, int *budget, int r, int id, char** combinationsMovies, int value, int begin, Combination* combination, int *totalCombinations);

void createCombination(Movie *movies, int totalMovies, int *budget, int r, int id, char** combinationsMovies, int value, int begin, Combination* combination, int *totalCombinations){
    value += movies[begin].value;
	
	if (begin < totalMovies && id != r) {
	    strcpy(combinationsMovies[id], (movies + begin)->name);
	    
	    for (int a = 0; a < 2; a++) {
	        auxCreateCombination(movies, totalMovies, budget, r, id + 1 - a, combinationsMovies, value, begin, combination, totalCombinations);    
	    
	        if (!a) value -= movies[begin].value;        
	    }
	} else if (id == r) {
	    addCombination(movies, totalMovies, combination, combinationsMovies, r, totalCombinations);
	}
}

void auxCreateCombination(Movie *movies, int totalMovies, int *budget, int r, int id, char** combinationsMovies, int value, int begin, Combination* combination, int *totalCombinations) {
    if(value <= *budget) createCombination(movies, totalMovies, budget, r, id, combinationsMovies, value, begin + 1, combination, totalCombinations);
}

long double fatorial(int totalMovies){
	return totalMovies == 0 ? 1 : (long double) totalMovies * fatorial(totalMovies-1);
}

Movie* fillMovies(int *totalMovies){
	Movie *movies = (Movie*)malloc(sizeof(Movie));
	char name[TOTAL_SIZE] = "";
	
	while(scanf("%s %d %d", name, &movies[*totalMovies].value, &movies[*totalMovies].totalFeatures) != EOF){
		strcpy(movies[*totalMovies].name, name);
		
		movies[*totalMovies].features = (int*)malloc(movies[*totalMovies].totalFeatures*sizeof(int));
		for(int i = 0; i < movies[*totalMovies].totalFeatures; i++) scanf("%d", &movies[*totalMovies].features[i]);

		(*totalMovies)++;
		movies = (Movie*)realloc(movies, (*totalMovies+1)*sizeof(Movie));
	}

    return movies;
}

int getTotalCombinations(int totalMovies){
	int counter = 0;
	long double combination = 0;
	while(++counter <= totalMovies) combination += fatorial(totalMovies)/(fatorial(counter)*fatorial(totalMovies-counter));
	
	return combination;
}

int main(){	
    int totalCombinations = 0, totalMovies = 0, budget;
    scanf("%d", &budget);

	Movie* movies = fillMovies(&totalMovies);
    
	Combination* combination = (Combination*)malloc(getTotalCombinations(totalMovies)*sizeof(Combination));
    for(int counter = 1; counter <= totalMovies; counter++){
		char *x[counter];
		
		for(int i = 0; i < counter; i++)	x[i] = (char*)malloc(TOTAL_SIZE*sizeof(char));
		
        createCombination(movies, totalMovies, &budget, counter, 0, x, 0, 0, combination, &totalCombinations);
	}


    int result = 0;
    for(int i = 0; i < totalCombinations; i++) if(combination[i].totalFeatures > result) result = combination[i].totalFeatures;
    
    printf("%d", result);
	
	return 0;
}