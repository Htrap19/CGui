#pragma once

#include <tuple>

namespace CGui
{
	namespace Function
	{
		template <typename Callable, typename ... Args>
		class Binder
		{
		public:
			Binder(Callable func, Args ... args);

			decltype(auto) operator()();

		protected:
			Callable m_Func;
			std::tuple<Args...> m_Args;
		};

		template <typename Callable, typename ... Args>
		Binder<Callable, Args...>::Binder(Callable func, Args ... args)
			: m_Func(func), m_Args(std::make_tuple(args...))
		{
		}

		template <typename Callable, typename ... Args>
		decltype(auto) Binder<Callable, Args...>::operator()()
		{
			auto parse_callback = [&](Args ... args) -> decltype(auto)
			{
				return m_Func(args...);
			};

			return std::apply(parse_callback, m_Args);
		}
	}

	namespace Class
	{
		template <typename Obj, typename Callable, typename ... Args>
		class Binder
		{
		public:
			using ObjPtr = Obj*;

		public:
			Binder(ObjPtr obj, Callable func, Args ... args);

			decltype(auto) operator()();

		protected:
			ObjPtr m_Obj;
			Callable m_Func;
			std::tuple<Args...> m_Args;
		};

		template <typename Obj, typename Callable, typename ... Args>
		Binder<Obj, Callable, Args...>::Binder(ObjPtr obj, Callable func, Args ... args)
			: m_Obj(obj), m_Func(func), m_Args(std::make_tuple(args...))
		{
		}

		template <typename Obj, typename Callable, typename ... Args>
		decltype(auto) Binder<Obj, Callable, Args...>::operator()()
		{
			auto parse_callback = [&](Args ... args) -> decltype(auto)
			{
				return (m_Obj->*m_Func)(args...);
			};

			return std::apply(parse_callback, m_Args);
		}
	}
}