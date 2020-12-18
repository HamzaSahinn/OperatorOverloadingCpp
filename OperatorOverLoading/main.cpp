#include<iostream>
using namespace std;
class Rational{
private:
    int numerator;
    int denominator;
public:
    int get_numerator(){
        return numerator;
    }
    int get_denominator(){
        return denominator;
    }
    void set_numerator(int a){
        numerator = a;
    }
    void set_denominator(int a){
        denominator = a;
    }
    Rational operator+(Rational r){
        Rational temp;
        int t = this->get_numerator()*r.get_denominator() + this->get_denominator()*r.get_numerator();
        temp.set_numerator(t);
        t = this->get_denominator()*r.get_denominator();
        temp.set_denominator(t);
        return temp;
    }
    Rational operator-(Rational r){
        Rational temp;
        int t= this->get_numerator()*r.get_denominator() - this->get_denominator()*r.get_numerator();
        temp.set_numerator(t);
        t = this->get_denominator()*r.get_denominator();
        temp.set_denominator(t);
        return temp;
    }
    Rational operator*(Rational r){
        Rational temp;
        int t = this->get_numerator()*r.get_numerator();
        temp.set_numerator(t);
        t= this->get_denominator()*r.get_denominator();
        temp.set_denominator(t);
        return temp;
    }
    Rational operator/(Rational r){
        Rational temp;
        int t = this->get_numerator()*r.get_denominator();
        temp.set_numerator(t);
        t = this->get_denominator()*r.get_numerator();
        temp.set_denominator(t);
        return temp;
    }
    double Value(Rational r){
        return (r.get_numerator() / r.get_denominator());
    }

    friend ostream &operator<<( ostream &output, const Rational &r ) {
        output <<r.numerator << '/' << r.denominator;
        return output;
    }

    friend istream &operator>>( istream  &input, Rational &r ) {
        char slash = '/';
        cout << "Enter a Rational number in the form A/B :" ;
        int n, d;
        cin >> n >> slash >> d;
        r.set_numerator(n);
        r.set_denominator(d);
        return input;
    }
};

// driver main program
int main(void){
    Rational x, y, z;
    x.set_numerator(0); x.set_denominator(1);
    y.set_numerator(0); y.set_denominator(1);
    z.set_numerator(0); z.set_denominator(1);
    double v;
    cout << "The rational number created by the constructor = ";
    cout <<x<< endl;
    cin>>x;
    cout << "The rational number input = ";
    cout <<x<<endl;
    cin>>y;
    z = x + y;
    cout <<x<< " + "<<y<<" = "<< z << endl;
    z = x - y;
    cout<<x<<" - "<<y<<"="<<z<<endl;
    z = x * y;
    cout<<x<<" * "<<y<<"="<<z<<endl;
    z = x / y;
    cout<<x<<" / "<<y<<"="<<z<<endl;
    v = z.Value(z);
    cout << "The value of "<<z<<" = " << v << endl;
    return 0;
}