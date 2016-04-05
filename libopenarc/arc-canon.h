/*
**  Copyright (c) 2007, 2008 Sendmail, Inc. and its suppliers.
**    All rights reserved.
**
**  Copyright (c) 2009, 2011, 2012, The Trusted Domain Project.
**    All rights reserved.
*/

#ifndef _ARC_CANON_H_
#define _ARC_CANON_H_

#include "build-config.h"

/* system includes */
#include <sys/types.h>
#ifdef HAVE_STDBOOL_H
# include <stdbool.h>
#endif /* HAVE_STDBOOL_H */

/* libopenarc includes */
#include "arc.h"
#include "arc-types.h"

#define	ARC_HASHBUFSIZE	4096

/* prototypes */
extern ARC_STAT arc_add_canon __P((ARC_MESSAGE *, _Bool, int,
                                   u_char *, struct arc_hdrfield *,
                                   ssize_t length, ARC_CANON **));
extern ARC_STAT arc_canon_bodychunk __P((ARC_MESSAGE *, u_char *, size_t));
extern void arc_canon_cleanup __P((ARC_MESSAGE *));
extern ARC_STAT arc_canon_closebody __P((ARC_MESSAGE *));
extern ARC_STAT arc_canon_getfinal __P((ARC_CANON *, u_char **, size_t *));
extern ARC_STAT arc_canon_gethashes __P((ARC_MESSAGE *, void **, size_t *,
                                         void **, size_t *));
extern ARC_STAT arc_canon_header_string __P((struct arc_dstring *,
                                             unsigned char *,
                                             size_t, _Bool));
extern ARC_STAT arc_canon_init __P((ARC_MESSAGE *, _Bool, _Bool));
extern u_long arc_canon_minbody __P((ARC_MESSAGE *));
extern ARC_STAT arc_canon_runheaders __P((ARC_MESSAGE *));
extern int arc_canon_selecthdrs __P((ARC_MESSAGE *, u_char *,
                                     struct arc_hdrfield **, int));
extern ARC_STAT arc_canon_seal __P((ARC_MESSAGE *, struct arc_hdrfield *));

#endif /* ! _ARC_CANON_H_ */
