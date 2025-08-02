#include <stdio.h>
#include <string.h>
#include <time.h>

int main() {
    char target[1000];
    char input[1000];
    time_t start, end;
    int choose;

    printf("Choose difficulty level\n");
    printf("1. Beginner\n");
    printf("2. Medium\n");
    printf("3. Hard\n");
    scanf("%d", &choose);
    getchar(); // To consume leftover newline

    printf("Type the sentence as fast as you can.\n");
    printf("Press Enter when you're ready to start typing...");
    getchar(); // Wait for Enter

    // Set sentence based on choice
    switch(choose){
        case 1:
            strcpy(target, "The quick brown fox jumps over the lazy dog");
            break;
        case 2:
            strcpy(target, "Despite repeated failures, persistence eventually transforms effort into mastery");
            break;
        case 3:
            strcpy(target, "Zebras quietly zigzag through bizarre quantum fields, analyzing juxtaposed phenomena without hesitation");
            break;
        default:
            printf("Invalid choice. Exiting.\n");
            break;
    }

    printf("\nThe sentence is:\n%s\n", target);
    printf("Start typing and press Enter when done:\n");

    time(&start); // Start timer
    fgets(input, sizeof(input), stdin); // User types sentence
    time(&end);   // End timer

    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

    double time_taken = difftime(end, start); // Calculate time taken

    // Accuracy check
    if(strcmp(target, input) == 0) {
        printf("\n✅ Typing is accurate!\n");

        if(time_taken < 15){
             printf("You typed: %s\n", input);
    printf("Time taken: %.2f seconds\n", time_taken);
            printf("You are a Typing Ninja! 🥷\n");
        }
        else if(time_taken < 23){
             printf("You typed: %s\n", input);
    printf("Time taken: %.2f seconds\n", time_taken);
            printf("You're a Pro! 😎\n");
        }
        else{
             printf("You typed: %s\n", input);
    printf("Time taken: %.2f seconds\n", time_taken);
            printf("Keep practicing, Beginner! 💪\n");
        }
    } else {
        printf("\n❌ There's a mismatch. Keep practicing!\n");
    }

    printf("You typed: %s\n", input);

    return 0;
}

