gcc -o libmsadd libmsadd.c cgifunc.c files.c accounts.c

if [ "$?" = "0" ]; then
	echo "Compiled: libsadd"
else
	echo "Some error."
	exit 1
fi

gcc -o libmsdta libmsdta.c cgifunc.c files.c accounts.c

if [ "$?" = "0" ]; then
	echo "Compiled: libmsdta"
else
	echo "Some error."
	exit 1
fi

gcc -o libmsrmv libmsrmv.c cgifunc.c files.c accounts.c

if [ "$?" = "0" ]; then
	echo "Compiled: libmsrmv"
else
	echo "Some error."
	exit 1
fi

gcc -o libmsvwa libmsvwa.c cgifunc.c files.c accounts.c

if [ "$?" = "0" ]; then
	echo "Compiled: libmsvwa"
else
	echo "Some error."
	exit 1
fi

gcc -o libmsadb libmsadb.c cgifunc.c files.c accounts.c

if [ "$?" = "0" ]; then
	echo "Compiled: libmsadb"
else
	echo "Some error."
	exit 1
fi

gcc -o libmsrmb libmsrmb.c cgifunc.c files.c accounts.c

if [ "$?" = "0" ]; then
	echo "Compiled: libmsrmb"
else
	echo "Some error."
	exit 1
fi

gcc -o libmschp libmschp.c cgifunc.c files.c accounts.c

if [ "$?" = "0" ]; then
	echo "Compiled: libmschp"
else
	echo "Some error."
	exit 1
fi

sudo cp libmsadd /usr/lib/cgi-bin/libmsadd

if [ "$?" = "0" ]; then
	echo "Installed: libsadd"
else
	echo "Some error."
	exit 1
fi

sudo cp libmsdta /usr/lib/cgi-bin/libmsdta

if [ "$?" = "0" ]; then
	echo "Installed: libmsdta"
else
	echo "Some error."
	exit 1
fi

sudo cp libmsrmv /usr/lib/cgi-bin/libmsrmv

if [ "$?" = "0" ]; then
	echo "Installed: libmsrmv"
else
	echo "Some error."
	exit 1
fi

sudo cp libmsvwa /usr/lib/cgi-bin/libmsvwa

if [ "$?" = "0" ]; then
	echo "Installed: libmsvwa"
else
	echo "Some error."
	exit 1
fi

sudo cp libmschp /usr/lib/cgi-bin/libmschp

if [ "$?" = "0" ]; then
	echo "Installed: libsadd"
else
	echo "Some error."
	exit 1
fi

sudo cp libmsadb /usr/lib/cgi-bin/libmsadb

if [ "$?" = "0" ]; then
	echo "Installed: libsadb"
else
	echo "Some error."
	exit 1
fi

sudo cp libmsrmb /usr/lib/cgi-bin/libmsrmb

if [ "$?" = "0" ]; then
	echo "Installed: libsrmb"
else
	echo "Some error."
	exit 1
fi
