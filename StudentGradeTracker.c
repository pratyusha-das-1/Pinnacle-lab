#include<stdio.h>
#define MAX_STUDENTS 100
#define MAX_SUBJECTS 5
typedef struct student{
    char name[20];
    int marks[5];
    float average;
    char grade;
}s;
void average(s *st ){
    float total=0;
    for(int i=0;i<MAX_SUBJECTS;i++){
        total+=st->marks[i];
    }
    st->average=total/5.0;
}
void assignGrades(s *st){
    if(st->average>=90){
        st->grade='A';
    }
    else if(st->average>=80){
        st->grade='B';
    }
    else if(st->average>=70){
        st->grade='C';
    }
    else if(st->average>=50){
        st->grade='D';
    }
    else{
        st->grade='F';
    }
}
void printReportCard(s st){
    printf("\n######## REPORT CARD ########\n\n");
    printf("Name of the student : %s\n",st.name);
    for(int i=0;i<MAX_SUBJECTS;i++){
        printf("Marks of subject %d(out of 100):%d\n",i+1,st.marks[i]);
    }
    printf("Average:%.2f\n",st.average);
    printf("Grade:%c\n",st.grade);
    printf("************************************\n\n");
}
int main(){
    int numStudent,sub;
    printf("Enter number of student(max %d):",MAX_STUDENTS);
    scanf("%d",&numStudent);
    if(numStudent>MAX_STUDENTS){
        printf("ERROR!Maximum student limit exceeded.\n");
        return 1;
    }
    s st[MAX_STUDENTS];
    for( int i=0;i<numStudent;i++){
        printf("\nEnter the details for student %d:\n",i+1);
        printf("Name:");
        scanf("%s",&st[i].name);

        for(int j=0;j<MAX_SUBJECTS;j++){
            printf("Enter subject %d marks(out of 100):",j+1);
            scanf("%d",&st[i].marks[j]);
        }
    }
    for(int i=0;i<numStudent;i++){
        average(&st[i]);
        assignGrades(&st[i]);
        printReportCard(st[i]);
    }
    return 0;

}
