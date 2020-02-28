
#include <iostream>

#include "Vector.h"

Vector::Vector(size_t size)
    : capacity(size), content(new int[size]), last(content) {}

Vector::Vector() : Vector(10) {}

Vector::Vector(const size_t length , const int *const content) : Vector
(Checker(length)) {

  for (size_t i = 0; i < length; i++) {
    this->content[i] = content[i];
    ++last;
  }
} // left * const на ссылку, правая просто не менять

Vector::Vector(const Vector &original) // копирование
    : Vector(original.capacity) {
  for (size_t i = 0; i < capacity; i++) {
    content[i] = original.content[i];
    ++last;
  }
}

size_t Vector::get_size() const { return last - content; }

void Vector::resize() {
  const auto size = get_size();
  if ( size % 10 == 0) {
    const auto new_content = new int[size + 10];// выделили новую память

    for (size_t i = 0; i < capacity; i++) {
      //скопировали данные в новый
      // массив с вновой памятью
      new_content[i] = content[i];
    }

    delete[] content;

    content = new_content;// new pamat
    last = content + size; // ссылка на последний
  }
}

size_t Vector::Push_back(int value) {
    resize();
    *last = value;// adres
     ++last;
}

size_t Vector::Size(size_t length, int *content) { return length; }
Vector::~Vector() { delete[] content; }
