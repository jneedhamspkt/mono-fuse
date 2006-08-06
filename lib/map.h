/*
 * This file was automatically generated by make-map from Mono.Fuse.dll.
 *
 * DO NOT MODIFY.
 */
#include <config.h>

#ifndef INC_Mono_Fuse_map_H
#define INC_Mono_Fuse_map_H

#include <glib/gtypes.h>

G_BEGIN_DECLS

/*
 * Enumerations
 */
#ifndef FUSE_USE_VERSION
#define FUSE_USE_VERSION 25
#endif /* ndef FUSE_USE_VERSION=25 */
#include <fuse.h>

/*
 * Structure Declarations
 */

struct Mono_Fuse_Args;
struct Mono_Fuse_FileSystemOperationContext;
struct Mono_Fuse_OpenedFileInfo;
struct Mono_Fuse_Operations;
struct Mono_Posix_Stat;
struct Mono_Posix_Statvfs;
struct Mono_Posix_Utimbuf;
/*
 * Delegate Declarations
 */

typedef int (*AccessCb) (const char* path, int mode);
typedef int (*ChangeOwnerCb) (const char* path, gint64 owner, gint64 group);
typedef int (*ChangePermissionsCb) (const char* path, unsigned int mode);
typedef int (*ChangeTimesCb) (const char* path, struct Mono_Posix_Utimbuf* buf);
typedef int (*CloseDirectoryCb) (const char* path, struct Mono_Fuse_OpenedFileInfo* info);
typedef int (*CreateCb) (const char* path, unsigned int mode, struct Mono_Fuse_OpenedFileInfo* info);
typedef int (*CreateDirectoryCb) (const char* path, unsigned int mode);
typedef int (*CreateFileNodeCb) (const char* path, unsigned int perms, guint64 dev);
typedef int (*CreateHardlinkCb) (const char* oldpath, const char* newpath);
typedef int (*CreateSymbolicLinkCb) (const char* oldpath, const char* newpath);
typedef void (*DestroyCb) (void* privateData);
typedef int (*FlushCb) (const char* path, struct Mono_Fuse_OpenedFileInfo* info);
typedef int (*GetExtendedAttributesCb) (const char* path, const char* name, unsigned char* value, guint64 size);
typedef int (*GetFileAttributesCb) (const char* path, struct Mono_Posix_Stat* stat);
typedef int (*GetFileDescriptorAttributesCb) (const char* path, struct Mono_Posix_Stat* buf, struct Mono_Fuse_OpenedFileInfo* info);
typedef int (*GetFileSystemStatisticsCb) (const char* path, struct Mono_Posix_Statvfs* buf);
typedef void* (*InitCb) (void);
typedef int (*ListExtendedAttributesCb) (const char* path, unsigned char* list, guint64 size);
typedef int (*OpenCb) (const char* path, struct Mono_Fuse_OpenedFileInfo* info);
typedef int (*OpenDirectoryCb) (const char* path, struct Mono_Fuse_OpenedFileInfo* info);
typedef int (*ReadCb) (const char* path, unsigned char* buf, guint64 size, gint64 offset, struct Mono_Fuse_OpenedFileInfo* info);
typedef int (*ReadDirectoryCb) (const char* path, const char*** paths, struct Mono_Fuse_OpenedFileInfo* info);
typedef int (*ReadSymbolicLinkCb) (const char* path, char* buf, guint64 bufsize);
typedef int (*ReleaseCb) (const char* path, struct Mono_Fuse_OpenedFileInfo* info);
typedef int (*RemoveDirectoryCb) (const char* path);
typedef int (*RemoveExtendedAttributesCb) (const char* path, const char* name);
typedef int (*RemoveFileCb) (const char* path);
typedef int (*RenameFileCb) (const char* oldpath, const char* newpath);
typedef int (*SetExtendedAttributesCb) (const char* path, const char* name, unsigned char* value, guint64 size, int flags);
typedef int (*SynchronizeDirectoryCb) (const char* path, int onlyUserData, struct Mono_Fuse_OpenedFileInfo* info);
typedef int (*SynchronizeFileDescriptorCb) (const char* path, int onlyUserData, struct Mono_Fuse_OpenedFileInfo* info);
typedef int (*TruncateCb) (const char* path, gint64 length);
typedef int (*TruncateFileDescriptorCb) (const char* path, gint64 length, struct Mono_Fuse_OpenedFileInfo* info);
typedef int (*WriteCb) (const char* path, unsigned char* buf, guint64 size, gint64 offset, struct Mono_Fuse_OpenedFileInfo* info);
/*
 * Structures
 */

struct Mono_Fuse_Args {
	int   argc;
	void* argv;
	int   allocated;
};

int
Mono_Fuse_FromArgs (struct Mono_Fuse_Args* from, struct fuse_args *to);int
Mono_Fuse_ToArgs (struct fuse_args *from, struct Mono_Fuse_Args* to);


struct Mono_Fuse_FileSystemOperationContext {
	void*  fuse;
	gint64 UserId;       /* uid_t */
	gint64 GroupId;      /* gid_t */
	gint64 ProcessId;    /* pid_t */
	void*  PrivateData;
};

struct Mono_Fuse_OpenedFileInfo {
	int     Flags;
	int     WritePage;
	int     DirectIO;
	int     KeepCache;
	guint64 FileHandle;
};

struct Mono_Fuse_Operations {
	GetFileAttributesCb           getattr;
	ReadSymbolicLinkCb            readlink;
	CreateFileNodeCb              mknod;
	CreateDirectoryCb             mkdir;
	RemoveFileCb                  unlink;
	RemoveDirectoryCb             rmdir;
	CreateSymbolicLinkCb          symlink;
	RenameFileCb                  rename;
	CreateHardlinkCb              link;
	ChangePermissionsCb           chmod;
	ChangeOwnerCb                 chown;
	TruncateCb                    truncate;
	ChangeTimesCb                 utime;
	OpenCb                        open;
	ReadCb                        read;
	WriteCb                       write;
	GetFileSystemStatisticsCb     statfs;
	FlushCb                       flush;
	ReleaseCb                     release;
	SynchronizeFileDescriptorCb   fsync;
	SetExtendedAttributesCb       setxattr;
	GetExtendedAttributesCb       getxattr;
	ListExtendedAttributesCb      listxattr;
	RemoveExtendedAttributesCb    removexattr;
	OpenDirectoryCb               opendir;
	ReadDirectoryCb               readdir;
	CloseDirectoryCb              releasedir;
	SynchronizeDirectoryCb        fsyncdir;
	InitCb                        init;
	DestroyCb                     destroy;
	AccessCb                      access;
	CreateCb                      create;
	TruncateFileDescriptorCb      ftruncate;
	GetFileDescriptorAttributesCb fgetattr;
};

int
Mono_Fuse_FromOperations (struct Mono_Fuse_Operations* from, struct fuse_operations *to);int
Mono_Fuse_ToOperations (struct fuse_operations *from, struct Mono_Fuse_Operations* to);



/*
 * Functions
 */
void mfh_destroy (void* fusep);
void* mfh_fuse_new (int fd, struct Mono_Fuse_Args* args, struct Mono_Fuse_Operations* ops);
int mfh_get_fuse_context (struct Mono_Fuse_FileSystemOperationContext* context);
int mfh_mount (const char* path, struct Mono_Fuse_Args* args);
int mfh_unmount (const char* path);

G_END_DECLS

#endif /* ndef INC_Mono_Posix_../map_H */

