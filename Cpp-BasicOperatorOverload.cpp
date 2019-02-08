// https://www.hackerrank.com/challenges/box-it/problem
// Solution is the two overloads from lines 21 to 31, rest is pre-filled

#include<bits/stdc++.h>

using namespace std;

class Box {
private:
    int length, breadth, height;
public:
    Box() { length = 0; breadth = 0; height = 0; }
    Box(int l, int b, int h) { length = l; breadth = b; height = h; }
    Box(Box &b) { length = b.getLength(); breadth = b.getBreadth(); height = b.getHeight(); }

    int getLength() { return length; }
    int getBreadth() { return breadth; }
    int getHeight() { return height; }
    long long CalculateVolume() { return (long long)length * breadth * height; }
    
    friend bool operator<(Box &B1, Box &B2) {
        if ( B1.length < B2.length 
            || ((B1.breadth < B2.breadth) && (B1.length == B2.length)) 
            || ((B1.height < B2.height) && (B1.breadth == B2.breadth) && (B1.length == B2.length)) )
            return true;
        return false;
    }
    friend ostream& operator<<(ostream& out, Box& B) {
        out << B.length << " " << B.breadth << " " << B.height;
        return out;
    }
};

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
