
//=============================================================================
/**
 *  @file    be_operation.cpp
 *
 *  $Id$
 *
 *  Extension of class AST_Operation that provides additional means for C++
 *  mapping.
 *
 *
 *  @author Copyright 1994-1995 by Sun Microsystems
 *  @author Inc. and Aniruddha Gokhale
 */
//=============================================================================


#include "be_operation.h"
#include "be_operation_strategy.h"
#include "be_predefined_type.h"
#include "be_argument.h"
#include "be_visitor.h"

#include "ast_exception.h"

#include "utl_err.h"
#include "utl_exceptlist.h"

#include "global_extern.h"

be_operation::be_operation (void)
  : COMMON_Base (),
    AST_Decl (),
    UTL_Scope (),
    AST_Operation (),
    be_scope (),
    be_decl (),
    original_operation_ (0)
{
  ACE_NEW (this->strategy_,
           be_operation_default_strategy (this));
}

be_operation::be_operation (AST_Type *rt,
                            AST_Operation::Flags fl,
                            UTL_ScopedName *n,
                            bool local,
                            bool abstract)
  : COMMON_Base (local,
                 abstract),
    AST_Decl (AST_Decl::NT_op,
              n),
    UTL_Scope (AST_Decl::NT_op),
    AST_Operation (rt,
                   fl,
                   n,
                   local,
                   abstract),
    be_scope (AST_Decl::NT_op),
    be_decl (AST_Decl::NT_op,
             n),
    original_operation_ (0)
{
  ACE_NEW (this->strategy_,
           be_operation_default_strategy (this));

  if (this->imported ())
    {
      return;
    }

  idl_global->operation_seen_ = true;

  if (!this->is_local ())
    {
      be_type *bt = be_type::narrow_from_decl (rt);
      bt->seen_in_operation (true);
      this->set_arg_seen_bit (bt);
      idl_global->non_local_op_seen_ = true;
    }
}


be_operation::~be_operation (void)
{
}

void
be_operation::destroy (void)
{
  if (0 != this->strategy_)
    {
      this->strategy_->destroy ();
      delete this->strategy_;
      this->strategy_ = 0;
    }

  // Call the destroy methods of our base classes.
  this->be_scope::destroy ();
  this->be_decl::destroy ();
  this->AST_Operation::destroy ();
}

int
be_operation::accept (be_visitor *visitor)
{
  return visitor->visit_operation (this);
}

AST_Argument *
be_operation::be_add_argument (AST_Argument *arg)
{
  this->add_to_scope (arg);
  this->add_to_referenced (arg,
                           0,
                           0);
  return arg;
}

int
be_operation::be_insert_exception (AST_Exception *ex)
{
  UTL_ExceptList *new_list = 0;
  ACE_NEW_RETURN (new_list,
                  UTL_ExceptList (ex,
                                  this->pd_exceptions),
                  -1);
  this->pd_exceptions = new_list;
  return 0;
}

be_operation_strategy *
be_operation::set_strategy (be_operation_strategy *new_strategy)
{
  be_operation_strategy *old = this->strategy_;

  if (new_strategy != 0)
    {
      this->strategy_ = new_strategy;
    }

  return old;
}

TAO_CodeGen::CG_STATE
be_operation::next_state (TAO_CodeGen::CG_STATE current_state,
                          int is_extra_state)
{
  return this->strategy_->next_state (current_state, is_extra_state);
}

int
be_operation::has_extra_code_generation (TAO_CodeGen::CG_STATE current_state)
{
  return this->strategy_->has_extra_code_generation (current_state);
}

be_operation*
be_operation::marshaling (void)
{
  return this->strategy_->marshaling ();
}

be_operation*
be_operation::arguments (void)
{
  return this->strategy_->arguments ();
}

void
be_operation::original_operation (be_operation *original_operation)
{
  this->original_operation_ = original_operation;
}

be_operation *
be_operation::original_operation (void)
{
  return this->original_operation_;
}

IMPL_NARROW_FROM_DECL (be_operation)
IMPL_NARROW_FROM_SCOPE (be_operation)
