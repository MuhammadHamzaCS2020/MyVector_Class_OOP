
/// Muhammad Hamza
/// 1602028
# include <iostream>
using namespace std;
class MyVector{
    private:
       int Lenth;
       double *ptr;
    public:
       MyVector();
       MyVector(int);
       MyVector(const MyVector&);  /// For Constructor Copy...
      ~MyVector();
      bool Redimention(int);
      void Display();
      int SIZE();
      void PushBack(int);
      /// Over Loaded Methods...
      double operator[](int);
      MyVector operator*(int);
      MyVector operator*(MyVector &);
      MyVector operator+(MyVector &);
      friend MyVector Calculation(MyVector & , MyVector &,char);
      friend MyVector Calculation(MyVector &,int);
      /// Friend Functions...
      friend MyVector operator*(MyVector & , int);
      friend MyVector operator*(MyVector & , MyVector &);
      friend MyVector operator+(MyVector & , MyVector &);
      friend void operator <<(ostream& out, MyVector &temp);

};

/// By Default Constructor with No Parameters...
MyVector::MyVector(){
  Lenth=0;
  ptr=NULL;
  cout<<"One object is Created that has zero Lenth and Null Pointer Array...\n";
}

// Constructor that has one int type parameter that the Lenth of Dynamically array
MyVector::MyVector(int len){
     this->Lenth=len;
     this->ptr=new double[len-1];
     for(int i=0; i<SIZE(); i++){
        ptr[i]=0;
     }
}

// Copy of a constructor...
MyVector::MyVector(const MyVector &temp){
   this->Lenth=temp.Lenth;
   this->ptr=temp.ptr;
     cout<<"Constructor Copy is Done...\n";
}

// Destructor Member Function...
MyVector::~MyVector(){
    delete ptr;
  cout<<"\nThanks for Using...";
}

// Re dimensioning of the Lenth...
bool MyVector::Redimention(int rd){
     MyVector temp1(rd);
     int temp=this->SIZE();
     cout<<"Your Past Vector SIZE was "<<SIZE();
     //this->Lenth=(this->Lenth)+(this->Lenth);
         for(int i=0; i<this->SIZE(); i++){
           temp1.ptr[i]=this->ptr[i];
         }
             /// Assign the zero that new cell create...
         for(int i=temp-1; i<temp1.SIZE(); i++){
            temp1.ptr[i]=0;
         }
     this->Lenth=temp1.Lenth;
     this->ptr=temp1.ptr;
     cout<<" But Now is "<<this->Lenth<<endl;
}
  /// SIZE find of My Vector...
 int MyVector::SIZE(){
      return this->Lenth;
}


                     ///   Member Functions Overloaded  ///

/// Index Value value Overloaded Function...
double MyVector::operator[](int index){
    return this->ptr[index];
}

   /// Simple Multiplication of a vector with a constant No...
 MyVector MyVector::operator*(int x){
   MyVector Simpl_Mutipl(this->Lenth);
      /// Display Multiple...
      for(int i=0; i<this->SIZE(); i++)
        Simpl_Mutipl.ptr[i]=(this->ptr[i])*x;
      return Simpl_Mutipl;
}
    /// Inner Product of two Vectors...
MyVector MyVector::operator*(MyVector &temp){
       int No;
       MyVector MULTIPLICATION;
     if(this->Lenth==temp.Lenth)
        No=this->Lenth;
    else if(this->Lenth > temp.Lenth)
        No=temp.Lenth;
    else
        No=this->Lenth;
      /// Display Multiple...
      for(int i=0; i<No; i++)
         MULTIPLICATION=(this->ptr[i])*(temp.ptr[i]);
      MULTIPLICATION.Lenth=No;
      return MULTIPLICATION;

}
    /// Inner Addition of two Vectors...
MyVector MyVector::operator+(MyVector &temp){
       int No;
     if(this->Lenth==temp.Lenth)
        No=this->Lenth;
    else if(this->Lenth > temp.Lenth)
        No=temp.Lenth;
    else
        No=this->Lenth;
       MyVector ADDER(No);
      for(int i=0; i<No; i++)
         ADDER.ptr[i]=(this->ptr[i])+(temp.ptr[i]);

      return ADDER;

}
// Display the Object Data...
void MyVector::Display(){
    cout<<"Lenth is : "<<this->Lenth<<endl;
      for(int i=0; i<SIZE(); i++){
           cout<<i+1<<" : "<<this->ptr[i]<<endl;
      }
    cout<<"Display is Done...\n";
}
                     ///Operator Overloading through Friend Functions...
/// Multiplication of Constant Variable with Vector Object...
 MyVector operator*(MyVector &obj , int x){
    MyVector temp(obj.Lenth);
    for(int i=0; i<obj.SIZE(); i++){
        temp.ptr[i]=(obj.ptr[i])*x;
    }
    return temp;
 }
  /// Multiplication of Two object vector through Friend Function...
 MyVector operator*(MyVector &obj1,MyVector &obj2){
     int len;
    if(obj1.Lenth>=obj2.Lenth)
      len=obj1.Lenth;// MyVector temp(obj1.Lenth);
    else
     len=obj2.Lenth;
     MyVector temp(len);
    for(int i=0; i<temp.SIZE(); i++){
        temp.ptr[i]=(obj1.ptr[i])*(obj2.ptr[i]);
    }
   return temp;
 }
  /// Addition of Two object vector through Friend Function...
 MyVector operator+(MyVector &obj1, MyVector &obj2){

      int len;
    if(obj1.Lenth>=obj2.Lenth)
      len=obj1.Lenth;
    else
     len=obj2.Lenth;
     MyVector temp(len);
    for(int i=0; i<temp.SIZE(); i++){
        temp.ptr[i]=(obj1.ptr[i])+(obj2.ptr[i]);
    }
   return temp;
 }




MyVector Calculation(MyVector &obj1, MyVector & obj2,char ch){
    if(ch=='*'){
        int len;
        if(obj1.SIZE()>=obj2.SIZE())
           len=obj1.SIZE();
        else
           len=obj2.SIZE();
         MyVector temp(len);
            for(int i=0; i<temp.SIZE(); i++){
               temp.ptr[i]=(obj1.ptr[i])*(obj2.ptr[i]);
            }
        return temp;
                  }
     else if(ch=='+'){
         int len;
           if(obj1.SIZE()>=obj2.SIZE())
              len=obj1.SIZE();
           else
              len=obj2.SIZE();
              MyVector temp(len);
                 for(int i=0; i<temp.SIZE(); i++){
                     temp.ptr[i]=(obj1.ptr[i])+(obj2.ptr[i]);
                 }
            return temp;
      }
}

MyVector Calculation(MyVector &obj,int x){
    MyVector temp(obj.Lenth);
    for(int i=0; i<obj.SIZE(); i++){
        temp.ptr[i]=(obj.ptr[i])*x;
    }
    return temp;
  }

                 ///  Operator Overloading through Non-Member Functions...
MyVector operator*=(MyVector &, int);
MyVector operator*=(MyVector &,MyVector &);
MyVector operator+=(MyVector &,MyVector &);



/// Multiplication of two Vector through Non-Member Function...
MyVector operator*=(MyVector &obj1, MyVector &obj2){
     MyVector temp;
     temp=Calculation(obj1,obj2,'*');
   return temp;
 }
MyVector operator+=(MyVector &obj1, MyVector &obj2){
     MyVector temp;
     temp=Calculation(obj1,obj2,'+');
     return temp;
 }
 MyVector operator*=(MyVector &obj1, int){
     MyVector temp;
     temp=Calculation(obj1,'A');
     return temp;
 }

/// Display Friend Function...
      void operator <<(ostream& out, MyVector &temp){
         for(int i=0; i<temp.SIZE(); i++){
            out<<temp.ptr[i]<<endl;
         }
      }


int main(int arg,char *argu[]){


// Build Any Object of MyVector Class and Do work...
}
