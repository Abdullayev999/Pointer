#include <iostream>
/*
		Задание 1: в пространстве имен pointer реализуйте шаблонный класс unique
		+ перегрузите операторы * и ->. Реализация этих операторов должна
		  соответствовать логике указателя
		+ реализуйте конструктор/оператор присваивания перемещением
		+ в деструкторе освободите память которая выделенна под данные
		+ если тип T указан как массив T[], то память
		  должна быть освобожена используя оператор delete[]
	*/


namespace Pointer
{
	template<typename T>
	class Unique
	{
	public:
		Unique(T* value = nullptr) {
			m_value = value;
		}

		~Unique()
		{
			if (m_value != nullptr)
			{
				delete m_value;
			}
		}

		T* operator -> ()
		{
			return m_value;
		}

		T& operator * ()
		{
			return *m_value;
		}

		Unique(const Unique&) = delete;

		Unique& operator = (const Unique&) = delete;

		Unique(Unique&& a) : m_value(a.m_value)
		{
			a.m_value = nullptr;
		}

		Unique& operator=(Unique&& other)
		{
			if (&other == this)
				return *this;

			delete m_value;

			m_value = other.m_value;
			other.m_value = nullptr;
			return *this;
		}

		friend std::ostream& operator<<(std::ostream& os, const Unique& n)
		{
			os << n.m_value;
			return os;
		}

	private:
		T* m_value;
	};

	template<typename T>
	class Unique<T[]>
	{
	public:
		Unique(T* value = nullptr) {
			m_value = value;
		}


		~Unique()
		{
			if (m_value != nullptr)
			{
				delete[] m_value;
			}
		}

		T* operator -> ()
		{
			return m_value;
		}

		T& operator * ()
		{
			return *m_value;
		}

		Unique(const Unique&) = delete;

		Unique& operator = (const Unique&) = delete;

		Unique(Unique&& a) : m_value(a.m_value)
		{
			a.m_value = nullptr;
		}

		Unique& operator=(Unique&& other)
		{
			if (&other == this)
				return *this;

			delete m_value;

			m_value = other.m_value;
			other.m_value = nullptr;
			return *this;
		}

		friend std::ostream& operator<<(std::ostream& os, const Unique& n)
		{
			os << n.m_value;
			return os;
		}

	private:
		T* m_value;
	};
}


int main()
{
	Pointer::Unique<int> ptr(new int(5));

	std::cout << " ptr = " << ptr << '\n';
	std::cout << " *ptr = " << *ptr << '\n';

}