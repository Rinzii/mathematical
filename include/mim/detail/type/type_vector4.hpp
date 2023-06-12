// Copyright (c) 2023-Present Mim contributors (see LICENSE)

#pragma once

#include "mim/detail/qualifier.hpp"

#include <iostream>

namespace mim
{
	template <typename T, qualifier Q>
	struct VectorT<4, T, Q> {
		using value_type = T;
		using type = VectorT<4, T, Q>;
		using size_type = size_t;
		static constexpr auto size_v = 4;

		// Data
		T x, y, z, w;

		static constexpr size_type size() noexcept { return size_v; }

		constexpr T& operator[](size_type i);
		constexpr T const& operator[](size_type i) const;

		// Many of these constructors use as reference section 5.4.1 of the GLSL 1.30.08 specification

		/// Constructors

		constexpr VectorT();

		constexpr VectorT(T x, T y, T z, T w);

		constexpr VectorT(VectorT<4, T, Q> const& v);

		constexpr explicit VectorT(T scalar);

		/// Template Constructors

		template <qualifier P>
		constexpr explicit VectorT(VectorT<4, T, P> const& v);

		// U Template Constructors

		template <typename U, qualifier P>
		constexpr explicit VectorT(VectorT<1, U, P> const& v);

		template <typename U, qualifier P>
		constexpr explicit VectorT(VectorT<4, U, P> const& v);

		// XYZW Template Constructors

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(X _x, Y _y, Z _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(VectorT<1, X, Q> const& _x, Y _y, Z _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(X _x, VectorT<1, Y, Q> const& _y, Z _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, Z _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(X _x, Y _y, VectorT<1, Z, Q> const& _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(VectorT<1, X, Q> const& _x, Y _y, VectorT<1, Z, Q> const& _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(X _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, W _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(VectorT<1, X, Q> const& _x, Y _y, Z _z, VectorT<1, W, Q> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(X _x, VectorT<1, Y, Q> const& _y, Z _z, VectorT<1, W, Q> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, Z _z, VectorT<1, W, Q> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(X _x, Y _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(VectorT<1, X, Q> const& _x, Y _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(X _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w);

		template <typename X, typename Y, typename Z, typename W>
		constexpr VectorT(VectorT<1, X, Q> const& _x, VectorT<1, Y, Q> const& _y, VectorT<1, Z, Q> const& _z, VectorT<1, W, Q> const& _w);

		// ABC Template Constructors

		template <typename A, typename B, typename C, qualifier P>
		constexpr VectorT(VectorT<2, A, P> const& _xy, B _z, C _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr VectorT(VectorT<2, A, P> const& _xy, VectorT<1, B, P> const& _z, C _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr VectorT(VectorT<2, A, P> const& _xy, B _z, VectorT<1, C, P> const& _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr VectorT(VectorT<2, A, P> const& _xy, VectorT<1, B, P> const& _z, VectorT<1, C, P> const& _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr VectorT(A _x, VectorT<2, B, P> const& _yz, C _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr VectorT(VectorT<1, A, P> const& _x, VectorT<2, B, P> const& _yz, C _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr VectorT(A _x, VectorT<2, B, P> const& _yz, VectorT<1, C, P> const& _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr VectorT(VectorT<1, A, P> const& _x, VectorT<2, B, P> const& _yz, VectorT<1, C, P> const& _w);

		template <typename A, typename B, typename C, qualifier P>
		constexpr VectorT(A _x, B _y, VectorT<2, C, P> const& _zw);

		template <typename A, typename B, typename C, qualifier P>
		constexpr VectorT(VectorT<1, A, P> const& _x, B _y, VectorT<2, C, P> const& _zw);

		template <typename A, typename B, typename C, qualifier P>
		constexpr VectorT(A _x, VectorT<1, B, P> const& _y, VectorT<2, C, P> const& _zw);

		template <typename A, typename B, typename C, qualifier P>
		constexpr VectorT(VectorT<1, A, P> const& _x, VectorT<1, B, P> const& _y, VectorT<2, C, P> const& _zw);

		// AB Template Constructors

		template <typename A, typename B, qualifier P>
		constexpr VectorT(VectorT<3, A, P> const& _xyz, B _w);

		template <typename A, typename B, qualifier P>
		constexpr VectorT(VectorT<3, A, P> const& _xyz, VectorT<1, B, P> const& _w);

		template <typename A, typename B, qualifier P>
		constexpr VectorT(A _x, VectorT<3, B, P> const& _yzw);

		template <typename A, typename B, qualifier P>
		constexpr VectorT(VectorT<1, A, P> const& _x, VectorT<3, B, P> const& _yzw);

		template <typename A, typename B, qualifier P>
		constexpr VectorT(VectorT<2, A, P> const& _xy, VectorT<2, B, P> const& _zw);

		/// Assignment Operators

		constexpr VectorT<4, T, Q>& operator=(VectorT<4, T, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator+=(U scalar);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator+=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator+=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator-=(U scalar);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator-=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator-=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator*=(U scalar);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator*=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator*=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator/=(U scalar);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator/=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator/=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator%=(U scalar);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator%=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator%=(VectorT<4, U, Q> const& v);

		/// Increment and Decrement Operators

		constexpr VectorT<4, T, Q>& operator++();

		constexpr VectorT<4, T, Q>& operator--();

		constexpr const VectorT<4, T, Q> operator++(int);

		constexpr const VectorT<4, T, Q> operator--(int);

		/// Bitwise Assignment Operators

		template <typename U>
		constexpr VectorT<4, T, Q>& operator&=(U scalar);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator&=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator&=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator|=(U scalar);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator|=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator|=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator^=(U scalar);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator^=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator^=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator<<=(U scalar);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator<<=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator<<=(VectorT<4, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator>>=(U scalar);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator>>=(VectorT<1, U, Q> const& v);

		template <typename U>
		constexpr VectorT<4, T, Q>& operator>>=(VectorT<4, U, Q> const& v);

		friend std::ostream& operator<<(std::ostream& os, VectorT<4, T, Q> const& v)
		{
			return os << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
		}


		/// Generic Function Declarations

		MIM_NODISCARD bool isfinite() const;
		VectorT<4, T, Q> sign() const;
		VectorT<4, T, Q> floor() const;
		VectorT<4, T, Q> ceil() const;
		VectorT<4, T, Q> round() const;
		VectorT<4, T, Q> min(const VectorT<4, T, Q>& v) const;
		VectorT<4, T, Q> max(const VectorT<4, T, Q>& v) const;

		T length() const;

		T length_squared() const;

		void normalize();

		VectorT<4, T, Q> normalized() const;

		MIM_NODISCARD bool is_normalized() const;

		T distance(const VectorT<4, T, Q>& v) const;

		T distance_squared(const VectorT<4, T, Q>& v) const;


		/// Function Declarations

		T dot(const VectorT<4, T, Q>& v) const;
		T cross(const VectorT<4, T, Q>& v) const;
		VectorT<4, T, Q> rotated(T angle) const;
		VectorT<4, T, Q> clamp(const VectorT<4, T, Q>& min, const VectorT<4, T, Q>& max) const;
		VectorT<4, T, Q> reflect(const VectorT<4, T, Q>& normal) const;
		VectorT<4, T, Q> refract(const VectorT<4, T, Q>& normal, T eta) const;
		VectorT<4, T, Q> project(const VectorT<4, T, Q>& normal) const;
	};

	/// Unary Operators

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v);

	/// Binary Operators

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v, T const& scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator+(T scalar, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator+(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator+(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v, T const& scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator-(T scalar, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator-(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator-(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator*(VectorT<4, T, Q> const& v, T const& scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator*(T scalar, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator*(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator*(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator*(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator/(VectorT<4, T, Q> const& v, T const& scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator/(T scalar, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator/(VectorT<4, T, Q> const& v1, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator/(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator/(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator%(VectorT<4, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator%(T scalar, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator%(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator%(VectorT<1, T, Q> const& scalar, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator%(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	/// Bitwise Binary Operators

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator&(VectorT<4, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator&(T scalar, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator&(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator&(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator&(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator|(VectorT<4, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator|(T scalar, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator|(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator|(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator|(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator^(VectorT<4, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator^(T scalar, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator^(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator^(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator^(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator<<(VectorT<4, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator<<(T scalar, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator<<(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator<<(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator<<(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator>>(VectorT<4, T, Q> const& v, T scalar);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator>>(T scalar, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator>>(VectorT<4, T, Q> const& v, VectorT<1, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator>>(VectorT<1, T, Q> const& v1, VectorT<4, T, Q> const& v);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator>>(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr VectorT<4, T, Q> operator~(VectorT<4, T, Q> const& v);

	/// Conditional Binary Operators

	template <typename T, qualifier Q>
	constexpr bool operator==(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <typename T, qualifier Q>
	constexpr bool operator!=(VectorT<4, T, Q> const& v1, VectorT<4, T, Q> const& v2);

	template <qualifier Q>
	constexpr bool operator&&(VectorT<4, bool, Q> const& v1, VectorT<4, bool, Q> const& v2);

	template <qualifier Q>
	constexpr bool operator||(VectorT<4, bool, Q> const& v1, VectorT<4, bool, Q> const& v2);


} // namespace mim

#include "mim/detail/type/type_vector4.inl"
#include "mim/detail/func/func_vector4.inl"
