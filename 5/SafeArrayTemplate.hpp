#ifndef SAFE_ARRAY_TEMPLATE
#define SAFE_ARRAY_TEMPLATE

template<typename T>
class SafeArray {
	public:
		SafeArray(int length);
		~SafeArray();
		
		SafeArray(const SafeArray& safeArray);
		SafeArray& operator=(const SafeArray& safeArray);
		
		SafeArray(const SafeArray&& array);
		SafeArray& operator=(const SafeArray&& safeArray);
		
		T& operator[](int index);
	private:
		int length;
		T *array;
};

#endif
