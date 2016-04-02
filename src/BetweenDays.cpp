/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int get_year(struct node* root);
int get_month(struct node* root);
int get_day(struct node* root);

int month_diff(int month1, int day1, int month2, int day2);

int between_days(struct node *date1head, struct node *date2head){
	if (date1head==NULL || date2head==NULL)
	return -1;
	int year1 = get_year(date1head);
	int month1 = get_month(date1head);
	int day1 = get_day(date1head);

	int year2 = get_year(date2head);
	int month2 = get_month(date2head);
	int day2 = get_day(date2head);
	if (year2 == year1 && month2 == month1)
		return abs(day1 - day2);
	else if (year1 == year2){
		return month_diff(month1, day1, month2, day2);
	}
	else{
		int sum=0,sum2=0;
		for (int i = year1 + 1; i < year2; i++){
			if (i % 4 == 0)
				sum += 366;
			else
				sum += 365;
		}
		printf("\nday=%d", sum);
		if (year1 < year2){
			 sum2 = month_diff(month1, day1, 12, 31) + 1+ month_diff(month2, day2, 1, 1) + 1;
		}
		else{
			sum2 = month_diff(month1, day1, 1, 1) + 1 + month_diff(month2, day2, 12, 31) + 1;
		}
		printf("\nday=%d", sum2);

		return (sum2 + sum);
	}
	return 1;
}

int month_diff(int month1, int day1, int month2, int day2){
	int months_days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month2 < month1){
		int temp = month2;
		month2 = month1;
		month1 = temp;
		temp = day1;
		day1 = day2;
		day2 = day1;
	}
	int num1 = months_days[month1-1] - day1;
	int num2 =day2;
	int sum = 0;
	month1++;
	while (month1 < month2){
		sum += months_days[month1++];
	}
	return (sum + num1 + num2);
}
int get_year(struct node* root){
	int temp_num = 1000, count = 5, ind = 1,year=0;
	struct node* temp = root;
	while (ind != count){
		temp = temp->next;
		ind++;
	}
	while (temp != NULL){
		year += temp->data*temp_num;
		temp_num /= 10;
		temp = temp->next;
	}
	return year;
}

int get_month(struct node* root){
	int  count = 3, ind = 1, month = 0;
	struct node* temp = root;
	while (ind != count){
		temp = temp->next;
		ind++;
	}
	month = temp->data * 10 + temp->next->data;
	return month;
}

int get_day(struct node* root){
	struct node* temp = root;
	return temp->data*10+temp->next->data;
}