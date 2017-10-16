/**
 * $Id:$
 * ***** BEGIN GPL/BL DUAL LICENSE BLOCK *****
 *
 * The contents of this file may be used under the terms of either the GNU
 * General Public License Version 2 or later (the "GPL", see
 * http://www.gnu.org/licenses/gpl.html ), or the Blender License 1.0 or
 * later (the "BL", see http://www.blender.org/BL/ ) which has to be
 * bought from the Blender Foundation to become active, in which case the
 * above mentioned GPL option does not apply.
 *
 * The Original Code is Copyright (C) 2002 by NaN Holding BV.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL/BL DUAL LICENSE BLOCK *****
 */

/* file.h juli 94 */


/*
 * 
 * 
 * 
 */

#ifndef FILE_H
#define FILE_H

/* flags voor wegschrijven/lezen scene */

#include <fcntl.h>
#include <unistd.h>
#include "storage.h"

#ifdef __FreeBSD__
  #include <sys/param.h>
  #include <sys/stat.h>
  #include <sys/mount.h>
#else   
  #ifdef linux
    #include <sys/vfs.h>
  #else
    #include <sys/statfs.h>  
  #endif
#endif


/* INTEGER CODES */

#define FORM MAKE_ID('F','O','R','M')
#define DDG1 MAKE_ID('3','D','G','1')
#define DDG2 MAKE_ID('3','D','G','2')
#define DDG3 MAKE_ID('3','D','G','3')
#define DDG4 MAKE_ID('3','D','G','4')

#define GOUR MAKE_ID('G','O','U','R')

#define BLEN MAKE_ID('B','L','E','N')
#define DER_ MAKE_ID('D','E','R','_')
#define V100 MAKE_ID('V','1','0','0')

#define DATA MAKE_ID('D','A','T','A')
#define GLOB MAKE_ID('G','L','O','B')
#define IMAG MAKE_ID('I','M','A','G')

#define DNA1 MAKE_ID('D','N','A','1')
#define TEST MAKE_ID('T','E','S','T')
#define REND MAKE_ID('R','E','N','D')
#define USER MAKE_ID('U','S','E','R')

#define ENDB MAKE_ID('E','N','D','B')

#
#
struct SDNA {
	char *data;
	int datalen, nr_names;
	char **names;
	int nr_types;
	char **types;
	short *typelens;
	int nr_structs;
	short **structs;
};

#
#
typedef struct BHead {
	int code, len;
	void *old;
	int SDNAnr, nr;
} BHead;


/* structs alleen voor files: (moeten WEL in SDNA) */

typedef struct FileGlobal {

	void *curscreen;
	short displaymode, winpos;
	char psx[80];
	
} FileGlobal;

extern short *findstruct_name(struct SDNA *sdna, char *str);
extern int findstruct_nr(struct SDNA *sdna, char *str);
extern int struct_compare(char *stype, void *one, void *two);
extern struct SDNA cur_sdna, old_sdna;	/* genfile.c */

#endif /* FILE_H */

