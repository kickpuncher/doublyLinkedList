#include <iostream>
#include "doublyLinkedList.h"

int main()
   {
   doublyLinkedList a;
   iterator i;
   iterator r;
   iterator reader;
   int count=0;

   a.pushfarRight(10);
   a.pushfarRight(11);
   a.pushfarLeft(9);
   a.pushfarLeft(8);
   
   i=a.iteratorPointfarLeft();
   r=a.iteratorPointfarRight();
   reader=a.iteratorPointfarLeft();
   r.goPrev();

   std::cout << "Far Left: " << a.getfarLeft() << " Far Right: " << a.getfarRight() << std::endl;
   std::cout << "Iterator i: " << i.getVal() << " Iterator r:  " << r.getVal() << std::endl;
   std::cout << "Distance: " << i.getDistance(r) << std::endl;
   std::cout << "Whole list: "; 
   count=0;
   reader=a.iteratorPointfarLeft();
      while(count<a.getSize()){
       std::cout << reader.getVal() << " ";
       reader.goNext();
       count++;
   }
   std::cout << std::endl;
   
   i.goNext();
//   i=a.iteratorPointfarRight();
   /*a.popIteratorNode(i);*/
   //std::cout << "popped iterator" << std::endl;
   a.pushIteratorNode(i,69);
 //  std::cout << "iterator i is at " << i.getVal();
   std::cout << "pushed to iterator" << std::endl;

   std::cout << "Whole list: "; 
   count=0;
   reader=a.iteratorPointfarLeft();
      while(count<a.getSize()){
       std::cout << reader.getVal() << " ";
       reader.goNext();
       count++;
   }
   std::cout << std::endl;

   a.popfarRight();
   a.popfarRight();
   a.popfarLeft();
   a.popfarLeft();

   a.pushfarRight(10);
   a.pushfarRight(11);
   a.pushfarLeft(9);
   a.pushfarLeft(8);

   //std::cout << "Whole list: "; 
   //count=0;
   //reader=a.iteratorPointfarLeft();
   //   while(count<a.getSize()){
   //    std::cout << reader.getVal() << " ";
   //    reader.goNext();
   //    count++;
   //}
   //std::cout << std::endl;
  // a.popfarRight();
 //  a.popfarLeft();

   //a.popfarLeft();
   doublyLinkedList b;
   }