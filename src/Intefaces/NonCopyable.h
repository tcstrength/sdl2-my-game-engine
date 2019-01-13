#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

class NonCopyable {
public:
    NonCopyable();

    NonCopyable(const NonCopyable& non);

    NonCopyable& operator=(const NonCopyable& non);
};

#endif // NONCOPYABLE_H
