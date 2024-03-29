fmt='
                   r=%(refname)
                   t=%(*objecttype)
                   T=${r#refs/tags/}

                   o=%(*objectname)
                   n=%(*authorname)
                   e=%(*authoremail)
                   s=%(*subject)
                   d=%(*authordate)
                   b=%(*body)

                   kind=Tag
                   if test "z$t" = z
                   then
# could be a lightweight tag
                           t=%(objecttype)
                           kind="Lightweight tag"
                           o=%(objectname)
                           n=%(authorname)
                           e=%(authoremail)
                           s=%(subject)
                           d=%(authordate)
                           b=%(body)
                   fi
                   echo "$kind $T points at a $t object $o"
                   if test "z$t" = zcommit
                   then
                           echo "The commit was authored by $n $e
           at $d, and titled

               $s
 Its message reads as:
           "
                           echo "$b" | sed -e "s/^/    /"
                           echo
                   fi
           '
