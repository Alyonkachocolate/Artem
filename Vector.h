//
// Created by pcc11 on 21.02.20.
//

#ifndef UNTITLED_VECTOR_H
#define UNTITLED_VECTOR_H

#include <cstddef>

size_t Checker(size_t length){
  return (length / 10 + (length % 10 == 0 ? 0 : 1)) * 10;
}

class Vector {

private:
  size_t capacity;// размер массива(память)
  int *content, *last;

  explicit Vector(size_t size);

  size_t get_size() const;// не изменияет ничего в объекте

  void resize();


public:
  Vector();                                     // 1 standard
  Vector(size_t length, const int *content);          // 3 with parameter
  Vector(const Vector &vector);                 // 2 copy
  size_t Push_back(int value); // 5
  size_t Size(size_t length, int *content);     // 6
  size_t Swap();                                // 7
  size_t Finder();                              // 8
                            //

  ~Vector();
};

#endif // UNTITLED_VECTOR_H
