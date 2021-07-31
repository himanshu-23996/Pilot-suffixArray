#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout); 
#endif

// INPUT

string s;
cin>>s;

// Adding the $ char 
s+="$";
int n = s.length();

// Declaring vars
vector< pair<char,int> > a(n);
vector <int> p(n), c(n);

// putting in index and the string in a, as a pair
for(int i=0;i<n;i++)
    a[i] = (make_pair(s[i],i));

// Sorting the string indices on the basis of chars
sort(a.begin(),a.end());

// Putting in the values of sorted indices in the suffix array, still it isn't fully sorted
for(int i=0;i<n;i++)
    p[i] = a[i].second;

// Initializing the equivalence class and filling it
c[p[0]] = 0;

for(int i=1;i<n;i++)
    {
        if(a[i].first==a[i-1].first)
            c[p[i]] = c[p[i-1]];
        else{
            c[p[i]] = c[p[i-1]] + 1;
        }
    }

// Finding / Transition via different values of k

int k = 0;
while((1<<k) < n)
{
    
// With an initial value of k = 0
    vector <pair<pair<int,int>,int> > a(n);
    for(int i=0;i<n;i++)
        a[i] = (make_pair(make_pair(c[i],c[(i+(1<<k))%n]),i));

// Sorting the indices on the basis of the first & second splits
    sort(a.begin(),a.end());

// Updating the suffix array
    for(int i=0;i<n;i++)
    p[i] = a[i].second;

// Intializing the Eqv class array
    c[p[0]] = 0;

    for(int i=1;i<n;i++)
        {
            if(a[i].first==a[i-1].first)
                c[p[i]] = c[p[i-1]];
            else{
                c[p[i]] = c[p[i-1]] + 1;
            }
        }

// Incrementing k
    k++;
}

// Displaying the output
for(int i=0;i<n;i++)
    cout<<p[i]<<" ";
cout<<endl;

return 0;
}