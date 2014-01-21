#ifndef FOO_H
#define FOO_H

#include <QQuickView>


class Foo {

public:
    Foo(QQuickView*);
    ~Foo();
    void foo(char*);
private:
    QQuickView* quickView;
};

#endif // FOO_H
