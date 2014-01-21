#include "foo.h"

void Foo::foo(char* foo)
{

}

Foo::Foo(QQuickView* view)
{
    this->quickView = view;
}

Foo::~Foo()
{
    this->quickView = null;
}
