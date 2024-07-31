#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define NUM_QUESTIONS 10
#define TIME_LIMIT 10
typedef struct quiz{
    char question[256];
    char options[4][256];
    int correct_option;
}quiz;
void displayQuestion(quiz q,int qno){
    printf("Question %d:%s\n",qno+1,q.question);
    for(int i=0;i<4;i++){
        printf("%d.%s\n",i+1,q.options[i]);
    }
}
int getAnswerWithTimeLimit(int time_limit) {
    time_t start, end;
    int answer;
    char buffer[256];

    time(&start);
    fgets(buffer, sizeof(buffer), stdin);
    time(&end);

    double time_taken = difftime(end, start);
    if (time_taken > time_limit) {
        return -1; // Indicate that time limit was exceeded
    } else {
        sscanf(buffer, "%d", &answer);
        return answer;
    }
}
void interface()
{
	printf("\n\t===============================================================================================");

	printf("\n\n\n\n\n} : } : } : } : } : } "
		": } : } : } : "
		"WELCOME TO ONLINE QUIZ APPLICATION "
		"	 : { : { : { : { : { "
		": { : { : { : {\n\n\n\n\n");
		printf("========================================================================================================================\n\n\n");
		printf("\t*************************you have 10 seconds to answer each question.***********************\n\n\n\n\n");

	system("pause");
}

int main() {
    interface();
    quiz q[NUM_QUESTIONS] = {
        {"The computer malware that disguises users by representing itself as legitimate software/program is known as …",{"Virus","worms","Trojans","Spyware"},3},
        {"Which among the following projects is launched to improve rural connectivity in backward area?",{"Param","Drishtee","Sirishtee","Vikas"},1},
        {"In which year did the Titanic sink?",{"1912","1914","2020","1872"},1},
        {"Who was the first woman to win a Nobel Prize?",{"Madam Curie"," Marie Curie","Mary Shelley","Virginia Woolf "},2},
        {"Who is known as the \'Father of Modern Physics\'?",{ "Louisa May Alcott","C.V.Raman","Albert Einstein","Satyendra Nath Bose"},3},
        {"What is the capital of France?", {"Paris", "London", "Berlin", "Madrid"}, 1},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Saturn"}, 2},
        {"Who invented Compact Disc?", {"James T. Russell","Fujio Masuoka","Thomas Edison","Martin Cooper"},1},
        {"What is the largest ocean on Earth?", {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"}, 4},
        {"Which gas makes up the majority of atmosphere of Earth?",{"oxygen","Sulpher","Neon","Nitrogen"},4}

    };
    int score=0;
    for(int i=0;i<NUM_QUESTIONS;i++){
            displayQuestion(q[i],i);
            printf("you have %d seconds to answer.\n",TIME_LIMIT);
            int answer=getAnswerWithTimeLimit(TIME_LIMIT);
            if (answer == -1) {
            printf("Time's up! Moving to the next question.\n\n");
        }
        else if(answer==q[i].correct_option){
            printf("Correct!!\n\n");
            score++;
        }
        else{
            printf("Wrong! The ans is %d.%s\n\n",q[i].correct_option,q[i].options[q[i].correct_option-1]);
        }

    }
    printf("Quiz over! Your score: %d/%d\n", score, NUM_QUESTIONS);
    return 0;
}

