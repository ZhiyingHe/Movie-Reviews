/*
 *  CSC A48 - Winter 2019 - Assignment 1 starter
 * 
 *  (c) 2019 Marzieh Ahmadzadeh and Francisco Estrada
 *  - No part of this code may be reproduced without written authorization
 * 
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout, and given in detail in the comments at the head of each
 * function below. 
 * 
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. At any point you can bring 
 * questions to your TAs or instructors during office hours. But please
 * remember:
 * 
 * - You should not post any assignment code on Piazza
 * - You should not share any part of your solution in any form
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always 
 *   safe to talk with your TAs.
 * 
 * All tasks to be completed by you are clearly labeled with a
 * ***** TO DO ****** comment block, which also gives you details
 * about what you have to implement. Look carefully and make sure
 * you don't miss a thing!
 * 
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with Part1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to Part1_driver.c
 * 
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/* Student identification:
 * 
 * Student Name (Last name, First name): He Zhiying
 * Student Number: 1004704769
 * UTORid: hezhiyi1
 * Your instructor's name is: Paco Estrada
 */

/* Academic Integrity Statement:
 * 
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 * 
 * Sign here with your name: Zhiying He
 */ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TO DO                               ********/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/***************************************************************************/

typedef struct MovieReview_struct
{    char movie_title[MAX_STR_LEN];
     char movie_studio[MAX_STR_LEN];
     int year;
     float BO_total;
     int score;
} MovieReview;

typedef struct ReviewNode_struct
{    MovieReview review;
     struct ReviewNode_struct *next;
} ReviewNode;

ReviewNode *newMovieReviewNode()
{
    /*
     * This function allocates a new, empty ReviewNode, and initializes the
     * contents of the MovieReview for this node to empty values.
     * The fields in the MovieReview should be set to:
     *  movie_title=""
     *  movie_studio=""
     *  year = -1
     *  BO_total = -1
     *  score = -1
     * 
     * The *next pointer for the new node MUST be set to NULL
     * 
     * The function must return a pointer to the newly allocated and initialized
     * node. If something goes wrong, the function returns NULL
     */
 
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *new_review=NULL;

    new_review = (ReviewNode *)calloc(1, sizeof(ReviewNode));
    strcpy(new_review -> review.movie_title, "");
    strcpy(new_review -> review.movie_studio, "");
    new_review -> review.year =-1;
    new_review ->review.BO_total =-1;
    new_review -> review.score =-1;
    new_review->next=NULL;

    return new_review;	// <--- This should change when after you implement your solution
}

ReviewNode *findMovieReview(const char title[MAX_STR_LEN], const char studio[MAX_STR_LEN], int year, ReviewNode *head)
{
    /*
     * This function searches through the linked list for a review that matches the input query. 
     * In this case, the movie review must match the title, studio, and year provided in the 
     * parameters for this function.
     * 
     * If a review matching the query is found, this function returns a pointer to the node that
     * contains that review. 
     * 
     * If no such review is found, this function returns NULL
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
    ReviewNode *p=NULL;

    if(head!=NULL){
        p=head;
        while(p!=NULL){
            if (strcmp(p ->review.movie_title, title)==0 && strcmp(p ->review.movie_studio, studio)==0 && \
            p ->review.year == year){
                return p;
            }
            p = p ->next;
        }
    }
    return NULL;
    
    // return NULL;}	// <--- This should change when after you implement your solution
}

ReviewNode *insertMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function inserts a new movie review into the linked list.
     * 
     * The function takes as input parameters the data neede to fill-in the review,
     * as well as apointer to the current head of the linked list.
     * 
     * If head==NULL, then the list is still empty.
     * 
     * The function inserts the new movie review *at the head* of the linked list,
     * and returns the pointer to the new head node.
     * 
     * The function MUST check that the movie is not already in the list before
     * inserting (there should be no duplicate entries). If a movie with matching
     * title, studio, and year is already in the list, nothing is inserted and the
     * function returns the current list head.
     */


    //If the list is empty or the movie review is not in the list.
    if (findMovieReview(title, studio, year, head)==NULL){
        ReviewNode *p=NULL;
            p=newMovieReviewNode();
            strcpy(p->review.movie_title, title);
            strcpy(p->review.movie_studio, studio);
            p->review.year=year;
            p->review.BO_total=BO_total;
            p->review.score=score;
            p->next=head;
            return p;
    }
    //If the movie review is already in the list.
    else{

        return head;
    }
    // else{
    //     p ->next=head ->next;
    // }
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    
    // return p;	// <--- This should change when after you implement your solution
}

int countReviews(ReviewNode *head)
{
  /*
   * This function returns the length of the current linked list. This requires
   * list traversal.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  

    int counter=0;
    ReviewNode *p=NULL;

    p=head;
    while(p!=NULL){
        counter++;
        p = p->next;
    }
    
    return counter;	// <--- This should change when after you implement your solution
}

void updateMovieReview(const char title[MAX_STR_LEN], const char studio[MAX_STR_LEN], int year, float BO_total, int score, ReviewNode *head)
{
    /*
     * This function looks for a review matching the input query [title, studio, year].
     * If such a review is found, then the function updates the Box-office total, and the score.
     * If no such review is found, the function prints out 
     * "Sorry, no such movie exists at this point"
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/
    ReviewNode *p=NULL;

    p=findMovieReview(title, studio, year,head);
    if(p!=NULL){
        p->review.BO_total=BO_total;
        p->review.score = score;
    }
}

ReviewNode *deleteMovieReview(char title[MAX_STR_LEN], char studio[MAX_STR_LEN],int year, ReviewNode *head)
{
    /*
     * This function removes a review matching the input query from the linked list. If no such review can
     * be found, it does nothing.
     * 
     * The function returns a pointer to the head of the linked list (which may have changed as a result
     * of the deletion process)
     */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *p=NULL;
    ReviewNode *q=NULL;

    p=head;

    if(findMovieReview(title, studio, year, head)!=NULL){
        if(p==findMovieReview(title, studio, year, head)){
            head = head->next;
            free(p);
        }
        else{
            while(p->next != NULL){
                q = p ->next;
                if(q==findMovieReview(title, studio, year, head)){
                    p->next = q->next;
                    free(q);
                    break;
                }
                p = p->next;
            }
        }
    }

    return head;	// <--- This should change when after you implement your solution
}

void printMovieReviews(ReviewNode *head)
{
    /*
     * This function prints out all the reviews in the linked list, one after another.
     * Each field in the review is printed in a separate line, with *no additional text*
     * (that means, the only thing printed is the value of the corresponding field).
     * 
     * Reviews are separated from each other by a line of
     * "*******************"
     * 
     * See the Assignment handout for a sample of the output that should be produced
     * by this function
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/

    ReviewNode *p=NULL;
    char line[]="**********************";

    p=head;
    while(p!=NULL){
        printf("%s \n", p->review.movie_title);
        printf("%s \n", p->review.movie_studio);
        printf("%d \n", p->review.year);
        printf("%f \n", p->review.BO_total);
        printf("%d \n", p->review.score);
        printf("%s \n", line);
        p = p->next;
    }
}

void queryReviewsByStudio(const char studio[MAX_STR_LEN], ReviewNode *head)
{
    /*
     * This function looks for reviews whose studio matches the input query.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/ 

    ReviewNode *p=NULL;
    char line[]="**********************";

    p=head;
    while(p!=NULL){
        if(strcmp(p->review.movie_studio, studio)==0){
            printf("%s \n", p->review.movie_title);
            printf("%s \n", studio);
            printf("%d \n", p->review.year);
            printf("%f \n", p->review.BO_total);
            printf("%d \n", p->review.score);
            printf("%s \n", line);
        }
        p=p->next;
    }
}

void queryReviewsByScore(int min_score, ReviewNode *head)
{
    /*
     * This function looks for reviews whose score is greater than, or equal to
     * the input 'min_score'.
     * It prints out the contents of all reviews matching the query in exactly
     * the same format used by the printMovieReviews() function above.
     */
    
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/  

    ReviewNode *p=NULL;
    char line[]="**********************";

    p=head;
    while(p!=NULL){
        if(p->review.score >= min_score){
            printf("%s \n", p->review.movie_title);
            printf("%s \n", p->review.movie_studio);
            printf("%d \n", p->review.year);
            printf("%f \n", p->review.BO_total);
            printf("%d \n", p->review.score);
            printf("%s \n", line);
        }
        p=p->next;
    }
}

ReviewNode *deleteReviewList(ReviewNode *head)
{
  /*
   * This function deletes the linked list of movie reviews, releasing all the
   * memory allocated to the nodes in the linked list.
   * 
   * Returns a NULL pointer so that the head of the list can be set to NULL
   * after deletion.
   */
      
    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/ 

    ReviewNode *p=NULL;
    ReviewNode *q=NULL;

    p=head; // Don't forget to set the traversal to head!!

    while(p!=NULL){
        q=p->next;
        free(p);
        p=q;
    }   

    return NULL;	// <--- This should change when after you implement your solution
}

ReviewNode *find_previous_box(ReviewNode *current_pointer, ReviewNode *head){
    ReviewNode *q=NULL;

    q=head;
    while(q->next!=NULL){
        if (q->next==current_pointer){
            return q;
        }
        q=q->next;
    }
    return NULL;
}

ReviewNode *swap_nearby(ReviewNode *current_traversal, ReviewNode *head){
     ReviewNode *q=NULL;
     ReviewNode *w=NULL;

    while(current_traversal!=head){
     q=find_previous_box(current_traversal, head);
    //  printf("found the previous pointer!");
     if(find_previous_box(q, head)!=NULL){
        w=current_traversal->next;
        find_previous_box(q, head)->next=current_traversal;
        current_traversal->next=q;
        q->next=w;
    }
     else{
         w=current_traversal->next;
         current_traversal ->next =q;
         q->next =w;
         head = current_traversal;
     }
    //  current_traversal=current_traversal->next;
    }
    return head;
}


ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
  /*
   * This function sorts the list of movie reviews in ascending order of movie
   * title. If duplicate movie titles exist, the order is arbitrary (i.e. you
   * can choose which one goes first).
   * 
   * However you implement this function, it must return a pointer to the head
   * node of the sorted list.
   */

    /***************************************************************************/
    /**********  TO DO: Complete this function *********************************/
    /***************************************************************************/      
    
    ReviewNode *p=NULL;
    ReviewNode *prev_ptr=NULL;
    ReviewNode *temp_ptr=NULL;
    // ReviewNode *next_pointer=NULL;
    
    
    if(head!=NULL){
        prev_ptr=head;
        p=prev_ptr->next;
    while(p!=NULL){
        if(strcmp(prev_ptr->review.movie_title, p->review.movie_title)>0){
            head=swap_nearby(p,head);
            temp_ptr=p;
            p=prev_ptr;
            prev_ptr=temp_ptr;
        }
        prev_ptr=prev_ptr->next;
        p=p->next;
        // if(p->next!=NULL){
        //     p=p->next;
        // }
        // else{
        //     break;
        // }
        
            }  }
        
    return head;	// <--- This should change when after you implement your solution
}