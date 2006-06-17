#!/bin/sh

mkdir test
cd test

# Create some files with names in UTF8
export LC_ALL=en_US.UTF-8
touch "Greek: Γειά σας"
touch "Hebrew: שלום"
touch "Russian: Здравствуйте!"
touch "Japanese: �����, ｺﾝﾆﾁﾊ"
touch "Chinese: ��"

cd ..
tar -cf test.tar test
