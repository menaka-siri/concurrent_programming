//
// Created by Siri on 12/15/2016.
//
/*!
 * @var operations_count  - int to hold the operations count
 *
 */
#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

int operations_count = -1;

/*!
 *
 * @param m - total operations count on the linkedList
 * @param p_member - probability of delete operation on the linkedList
 * @param p_insert - probability of delete operation on the linkedList
 * @param p_delete - probability of delete operation on the linkedList
 * @return - pointer to task_order array
 */
int *getTaskOrderArray(int m, float p_member, float p_insert, float p_delete) {//defining the probability of each function  --- starts
    operations_count = m;

    int *task_order = new int[m];
//        array<int,100> task_order;

    //initializing the task_order array elements with default values
    for(int i=0; i<m ; i++){
        task_order[i]=-1;
    }

    int task_order_count = 0;

    //fill the task_order array
    int member_count = (int) (m * p_member);
    cout <<"\nMember operations count:  "<< member_count <<endl;
    for(int i=0; i < (int)(m *p_member) ; i++){
        task_order[i] = 0;
        //cout <<"Loop counter:  "<< task_order_count <<"  element: "<< task_order[task_order_count]<<endl;
        task_order_count++;
    }
    cout <<"Task Order element: After Member: "<< task_order[task_order_count]<<endl;
    cout <<"Task Order count: After Member: "<<task_order_count<<endl;


    int insert_count = (int)(m * p_insert);
    cout <<"\nInsert operations count:  "<< insert_count <<endl;
    for(int i=0; i < (int)(m*p_insert) ; i++){
        task_order[task_order_count] = 1;
        //cout <<"Loop counter:  "<< task_order_count <<"  element: "<< task_order[task_order_count]<<endl;
        task_order_count++;
    }
    cout <<"Task Order element: After Insert: "<< task_order[task_order_count]<<endl;
    cout <<"Task Order count: After Insert: "<<task_order_count<<endl;

    int delete_count = (int)(m * p_delete);
    cout <<"\nDelete operations count:  "<< delete_count <<endl;
    for(int i=0; i < (int)(m*p_delete) ; i++){
        task_order[task_order_count] = 2;
        //cout <<"Loop counter:  "<< task_order_count <<"  element: "<< task_order[task_order_count]<<endl;
        task_order_count++;
    }
    cout <<"Task Order element: After Delete: "<< task_order[task_order_count]<<endl;
    cout <<"Task Order count: "<<task_order_count<<endl;

    //shuffling the task_order array items  --- starts

    //temporary vector to hold the contents of task_order array
    vector<int> temp_vector (task_order, task_order + m );

    shuffle (temp_vector.begin(), temp_vector.end(), default_random_engine(time(0)));

    copy(temp_vector.begin(), temp_vector.end(), task_order); //copy back the contents of the temp_vector to task_order array

    //shuffling the task_order array items  --- ends

    cout <<"\nTask Order elements: After shuffle "<<endl;
    for(int i=0; i< m ; i++){
        cout << task_order[i]<< "  ";
    }

    return task_order;
}

/*!
 *
 * @return  - (int) size of task_order array
 */
int getTaskOrderArraySize(){
    return operations_count;
}



//Source: http://www.softwareandfinance.com/CPP/MeanVarianceStdDevi.html
class StatisticCalc
{

private:

    int max = 100000;
    double *value ;
    double mean ;

public:

    int setValues(double *p, int count)
    {
        value = new double[count];

        if(count > max)
            return -1;

        max = count;

        for(int i = 0; i < count; i++)
            value[i] = p[i];
        return 0;
    }

    double calculateMean()
    {
        double sum = 0;
        for(int i = 0; i < max; i++)
            sum += value[i];
        return (sum / max);
    }

    double calculateSum()
    {
        double sum = 0;
        for(int i = 0; i < max; i++)
            sum += value[i];
        return (sum);
    }

    double calculateVariane()
    {
        mean = calculateMean();

        double temp = 0;
        for(int i = 0; i < max; i++)
        {
            temp += (value[i] - mean) * (value[i] - mean) ;
        }
        return temp / max;
    }

    double calculateSampleVariane()
    {
        mean = calculateMean();

        double temp = 0;
        for(int i = 0; i < max; i++)
        {
            temp += (value[i] - mean) * (value[i] - mean) ;
        }
        return temp / (max - 1);
    }


    double getStandardDeviation()
    {
        return sqrt(calculateVariane());
    }

    double getSampleStandardDeviation()
    {
        return sqrt(calculateSampleVariane());
    }

};
