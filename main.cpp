/*LOGIC OF THE PROGRAM:
                    we first take the page number number of maximum question in one page and questions in each page. now we take a variable 'pageNo' to keep
track of number of page and initialized it with 1 as page number start with 1 and one variable count1 for counting number of special questions. then we iterate over every page
and keep number of questions in that page in variable 'noq' then one variable 'last' to denote the last question of the page and one variable 'first' to denote the first
question of the page it start with 1 for every chapter and the 'last' variable we initialize it with zero so that we can later add the number of question in that page with 'last'
to obtain the last question number of the page. then we iterate until the end of the chapter (noq<0) and if its not the last page(noq>=k) then last question number will be last question of
previous page + k and then if the page no lies between the start and last question of the page then increment the 'count1' by 1 then decrement no. of questions by k and move on to the next page and also increment the 'first'
by k to denote the first question of the next page.
now if questions are less than k that means it is the last page of the chapter in that case we add remaining number of questions to our 'last' variable to to denote the last question of
the page. rest are same as previous condition just we don't increment the 'first' as in next step a new page will start.
and in the end we print the number of special question.

*/
#include<bits/stdc++.h>
using namespace std;
int fun(int n,int k,vector<int> arr )
{
    //track page no.
    int pageNo=1;
    //track special questions
    int count1=0;
    //iterate for all chapters.
    for(int i=0;i<n;i++)
    {
        int noq=arr[i];
        int last=0;
        int start=1;
        //if not last page
        while(noq>0)
        {
            if(noq>=k)
            {
                last+=k;
                if(start<=pageNo&&pageNo<=last)
                    count1++;
                 noq-=k;
                pageNo+=1;
                start+=k;
            }
          //for handling last pages with less than k questions
           else if(noq<k)
            {
                last+=noq;
                if(pageNo>=start&&pageNo<=last)
                    count1++;
                pageNo++;
                noq-=k;

            }

        }
    }
    return count1;
}
int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &values:arr)
    {
        cin >> values;
    }
   cout << fun(n,k,arr);

}

