
struct A
{
	int a = 4;
	int b = 1;
};


class UniquePointerOfA
{
	A* ptr;
public:
	UniquePointerOfA(A* ptr);


	UniquePointerOfA(const UniquePointerOfA&) = delete;
	UniquePointerOfA& operator=(const UniquePointerOfA&) = delete;

	UniquePointerOfA(UniquePointerOfA&&) noexcept;

	UniquePointerOfA& operator=(UniquePointerOfA&&) noexcept;

	A& operator*();
	const A& operator*() const;

	~UniquePointerOfA();
};