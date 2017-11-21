const int MAX_STACK_SIZE = 100000000;

template <class T>
class TStack{
	int size;
	int maxsize;
	T* array;
public:
	TStack(int _size=50)		// Конструктор 
	{
		if ( _size < 0 || _size > MAX_STACK_SIZE )
			throw _size;
		array = new T[_size];
		maxsize = _size;
		size = 0;
	}
	~TStack(){delete[] array;}
	TStack(const TStack& ts)		// Конструктор копирования
	{
		size = ts.size;
		maxsize = ts.maxsize;
		array = new T[maxsize];
		for(int i = 0; i < size; i++)
			array[i] = ts.array[i];
	}
	TStack& operator=(TStack& ts)
	{
		if ( this != &ts )	{
			if ( maxsize != ts.maxsize )	{
				delete[] array;
				maxsize = ts.maxsize;
				size = ts.size;
				array = new T[maxsize]; 
			}
			for ( int i = 0; i < size; i++ )
				array[i] = ts.array[i];
			return *this;
		}	else return *this;
	}
	void Clear(){size = 0;}
	int isfull(){return (size == maxsize);}
	int isempty(){return (size == 0);}
	T top()
	{
		if(isempty()) throw -1;
		return array[size-1];
	}
	T pop()
	{
		if(isempty()) throw -1;
		else	return array[--size];
	}
	void push(const T &el)
	{
		if(isfull()) throw -1;
		array[size] = el;
		size++;
	}
};