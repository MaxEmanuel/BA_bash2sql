cat zeitquery_s2.csv | sed -nr 's/query([^\|]*)\|real ([0-9])*m([^\|]*)s\|user ([^\|]*)\|([^\|]*)/\1,\2:\3/p'

