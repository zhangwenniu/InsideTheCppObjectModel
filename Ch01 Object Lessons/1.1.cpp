class Point {
public:
    Point( float xval );
    virtual ~Point();

    float x() const;
    static int PointCount();

protected:
    virtual ostream&
        print( ostream &os ) const;
    
    float _x;
    static int _point_count;
};

// C++支持单一继承：
class Library_materials { ... }; 
class Book : public Library_materials { ... };
class Rental_book : public Book { ... };


// C++ 也支持多重继承
// 原本的（更早于标准版的）iostream实现方式
class iostream:
    public istream,
    public ostream { ... };


// 甚至，继承关系也可以指定为虚拟（virtual，也就是共享的意思）：
class istream : virtual public ios { ... };
class ostream : virtual public ios { ... };

// How the Object Model Effects Programs


    X foobar()
    {
        X xx;
        X *pxx = new X;

        // foo() 是一个virtul function
        xx.foo();
        px->foo();

        delete px;
        return xx;
    };


// 这个函数有可能在内部被转化为：
// 可能的内部转换结果
// 虚拟C++代码

void foobar( X &_result )
{
    // 构造_result
    // _result 用来取代 local xx ...
    _result.X::X();

    // 扩展X *px = new X;
    px = _new( sizeof(X) );
    if (px != 0)
        px->X::X();
    
    // 扩展xx.foo()但不使用virtual机制
    // 以_result取代xx
    foo( &_result );

    // 使用virtual机制扩展px->foo()
    (*px->vtbl[ 2 ])( px )

    // 扩展delete px;
    if (px != 0){
        ( *px->vbtl[1]) ( px ); //destructor
        _delete(px);
    }

    // 无需使用named return statement
    // 无需摧毁local object xx
    return;
};