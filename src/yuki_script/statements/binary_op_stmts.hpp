#ifndef YUKI_SCRIPT_BINARY_OP_STMTS_HPP
#define YUKI_SCRIPT_BINARY_OP_STMTS_HPP


#include <functional>

#include "stmts.hpp"
#include "type_support/variable.hpp"


namespace yuki::statements
{

using binary_op_callback = std::function<yuki::type::variable(const yuki::type::variable & , const yuki::type::variable &)>;

class binary_op_stmt : public yuki::statements::evaluable_stmt
{
public:
	explicit binary_op_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs, const binary_op_callback & predicate):
		m_lhs(std::move(lhs)),
		m_rhs(std::move(rhs)),
		m_predicate(predicate)
	{}

	yuki::type::variable evaluate(yuki::context::context_stack & stack) override
	{
		const auto & var_lhs = m_lhs->evaluate(stack);
		const auto & var_rhs = m_rhs->evaluate(stack);
		return m_predicate(var_lhs, var_rhs);
	}

private:
	std::unique_ptr<yuki::statements::evaluable_stmt> m_lhs;
	std::unique_ptr<yuki::statements::evaluable_stmt> m_rhs;
	binary_op_callback m_predicate;

};


class or_stmt : public binary_op_stmt
{
public:
	explicit or_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
};

class and_stmt : public binary_op_stmt
{
public:
	explicit and_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
};



class l_stmt : public binary_op_stmt
{
public:
	explicit l_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
};

class leq_stmt : public binary_op_stmt
{
public:
	explicit leq_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
};

class g_stmt : public binary_op_stmt
{
public:
	explicit g_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
};

class geq_stmt : public binary_op_stmt
{
public:
	explicit geq_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
};

class eq_stmt : public binary_op_stmt
{
public:
	explicit eq_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
};

class neq_stmt : public binary_op_stmt
{
public:
	explicit neq_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
};



class addition_stmt : public binary_op_stmt
{
public:
	explicit addition_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
};

class substraction_stmt : public binary_op_stmt
{
public:
	explicit substraction_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
};

class multiplication_stmt : public binary_op_stmt
{
public:
	explicit multiplication_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
};

class division_stmt : public binary_op_stmt
{
public:
	explicit division_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
};

class modulo_stmt : public binary_op_stmt
{
public:
	explicit modulo_stmt(std::unique_ptr<yuki::statements::evaluable_stmt> && lhs, std::unique_ptr<yuki::statements::evaluable_stmt> && rhs);
};


}



















#endif























