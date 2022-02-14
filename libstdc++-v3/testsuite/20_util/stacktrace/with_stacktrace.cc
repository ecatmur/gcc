// { dg-options "-std=gnu++23 -lstdc++_libbacktrace" }
// { dg-do run { target c++23 } }
// { dg-require-effective-target stacktrace }

// Copyright (C) 2021-2022 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

#include <string>
#include <stdexcept>
#include <stacktrace>
#include <testsuite_hooks.h>

void test_throw()
{
  throw std::runtime_error("oops");
}

void test01()
{
  std::string s;
  try
    {
      test_throw();
    }
  catch([[with_stacktrace]] std::exception& e)
    {
      s = e.what();
    }
  VERIFY(s == "oops");
}

void test02()
{
  std::stacktrace st;
  try
    {
      test_throw();
    }
  catch([[with_stacktrace]] const std::exception& e)
    {
      st = std::stacktrace::from_current_exception();
    }
  std::string s = std::to_string(st);
  VERIFY(s.contains("test_throw"));
}

void test03()
{
  std::string s;
  try
    {
      test_throw();
    }
  catch([[with_stacktrace]] ...)
    {
      try
	{
	  throw;
	}
      catch(std::exception& e)
	{
	  s = e.what();
	}
    }
  VERIFY(s == "oops");
}

void test04()
{
  std::stacktrace st;
  try
    {
      test_throw();
    }
  catch([[with_stacktrace]] ...)
    {
      st = std::stacktrace::from_current_exception();
    }
  std::string s = std::to_string(st);
  VERIFY(s.contains("test_throw"));
}

int main()
{
  test01();
  test02();
  test03();
  test04();
}
