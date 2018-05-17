// MIT License

// Copyright (c) 2018 conghanting(conghting@gmail.com)

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// Singleton is a template class which can make the class inherited it be a
// singleton simplely.

#ifndef HERA_INCLUDE_SINGLETON_H_
#define HERA_INCLUDE_SINGLETON_H_

#include "noncopyable.h"

namespace hera 
{


// A singleton template class.
// Example:
//    Class CYourNewClass : hera::Singleton<CYourNewClass> { ...
//    ...
//    CYourNewClass* singleton_instance = CYourNewClass::instance();
template <typename T>
class Singleton : public Noncopyable
{
  private:
    struct object_creator
    {
      // This constructor does nothing more than ensure that instance()
      //  is called before main() begins, thus creating the static
      //  T object before multithreading race issues can come up.
      object_creator() { Singleton<T>::instance(); }
      inline void do_nothing() const { }
    };
    static object_creator create_object;

    Singleton();

  public:
    typedef T object_type;

    // If, at any point (in user code), Singleton<T>::instance()
    //  is called, then the following function is instantiated.
    static const object_type & instance()
    {
      // This is the object that we return a reference to.
      // It is guaranteed to be created before main() begins because of
      //  the next line.
      static object_type obj;

      // The following line does nothing else than force the instantiation
      //  of Singleton<T>::create_object, whose constructor is
      //  called before main() begins.
      create_object.do_nothing();

      return obj;
    }

    static object_type & mutable_instance()
    {
      // This is the object that we return a reference to.
      // It is guaranteed to be created before main() begins because of
      //  the next line.
      static object_type obj;

      // The following line does nothing else than force the instantiation
      //  of Singleton<T>::create_object, whose constructor is
      //  called before main() begins.
      create_object.do_nothing();

      return obj;
    }
};
template <typename T>
typename Singleton<T>::object_creator
Singleton<T>::create_object;

}
#endif