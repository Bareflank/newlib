#ifdef MALLOC_PROVIDED
/* ---------------------------------------------------------------------------*/
/* bareflank: start                                                           */
/* ---------------------------------------------------------------------------*/
/* breaks build, and why does this exist?                                     */
/* int _dummy_calloc = 1; */
/* ---------------------------------------------------------------------------*/
/* bareflank: end                                                             */
/* ---------------------------------------------------------------------------*/
#else
/* realloc.c -- a wrapper for realloc_r.  */

#include <_ansi.h>
#include <reent.h>
#include <stdlib.h>
#include <malloc.h>

#ifndef _REENT_ONLY

_PTR
_DEFUN (realloc, (ap, nbytes),
	_PTR ap _AND
	size_t nbytes)
{
  return _realloc_r (_REENT, ap, nbytes);
}

#endif
#endif /* MALLOC_PROVIDED */
