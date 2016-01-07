#include <iostream>
#include "Kund.h"
#include <random>
#include <queue>
#include <math.h>

using namespace std;

int main()
{
    srand(time(NULL));

    int hours;
    int nbrOfCustomers = -1;

    cout << "Typ in simulation time (hours): ";
    cin >> hours;
    if(hours<0)
        hours*(-1);
    while(nbrOfCustomers>60 || nbrOfCustomers<0){
        cout << "Type in number of customers per hour. (max 60): " << endl;
        cin >> nbrOfCustomers;
        if(nbrOfCustomers>60 || nbrOfCustomers<0){
            cout << "Please input a number lower than 60. And greater than 0" << endl;
        }
    }
    int minutes = hours*60;
    int nbrThisHour = 0;
    double newCustomers = 0;
    double rest = 0;
    int servedCustomers = 0;
    int totalQueueTime = 0;
    int TotalQueueLength = 0;
    queue<Kund> q;

    default_random_engine generator;
    poisson_distribution<int> distribution(nbrOfCustomers);

    // For every simulated minute:
    for(int i = 0; i != minutes; i++){
        // How many customers this hour?
        if(i % 60 == 0){
            // This can also be place outside the loop, then we just have to replace '60.0' to the variable 'minutes' bellow in the division.
            // And also multiply 'nbrOfCustomers' with the total number of hours above in the poisson_distribution declaration.
            nbrThisHour = distribution(generator);
        }
        // How many customers this minute? If rest, save it to next minute.
        newCustomers = ((double)nbrThisHour/60.0)+rest;
        rest = fmod(newCustomers, 1.0);
        newCustomers = (int)newCustomers;

        // Creates new customers and adds them to the last position in the queue.
        for(int j = 0; j != (int)newCustomers; j++){
            Kund customer(i);
            q.push(customer);
        }

        // If there is customers in the queue, serve the first one. If it's done in this minute, remove it from the queue.
        if(!q.empty()){
            if(q.front().isDone()){
                totalQueueTime += (i-q.front().getATid());
                servedCustomers++;
                q.pop();
            }
        }
        TotalQueueLength += q.size();
    }

    double avgQueueTime = ((double)totalQueueTime/(double)servedCustomers);
    double avgQueueLength = ((double)TotalQueueLength/(double)minutes);

    cout << endl << endl << "// -------------- Statistics -------------- \\\\" << endl;
    cout << "Total served customers: " << servedCustomers << " customers in " << hours << " hours." << endl;
    cout << "Average of customers: " << (servedCustomers/(double)hours) << " customers/hour." << endl;
    cout << "Average queue time: " << avgQueueTime << " min." << endl;
    cout << "Average queue length: " << avgQueueLength << " customers." << endl;
    cout << "// ---------------------------------------- \\\\" << endl;

    return 0;
}







