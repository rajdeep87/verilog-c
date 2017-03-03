#!/usr/bin/python

import sys
import re
import subprocess
import csv
import os

def processfile():

  src_path=sys.argv[1]
  
  properties=0
  verified_prop=0
  false_prop=0
  inconclusive_prop=0
  timeout_prop=0
  memout_prop=0
  error_prop=0
  sum_runtime=0.0
  sum_peak_memory=0.0
  decisions=0
  propagations=0
  conflicts=0
  conflict_literals=0
  learnt_clauses=0

  # temporary variable
  status=""
  f_name=""
  func_name=""
  time=""
  ver_time=0.0
  total_time=0.0

  status_decision = re.compile("Decisions::") 
  status_propagation = re.compile("Propagation::") 
  status_conflict  = re.compile("Learning Iterations::")
  status_conflict_literal = re.compile("Learnt literals::")
  status_learnt_clauses = re.compile("Learnt clauses::")
  status_time = re.compile("User time")
  
  for root, dirs, filenames in os.walk(src_path):
    for f in filenames:
      if f.endswith(".out"):
        log = open(src_path + f, 'r')
        lines=[line for line in log]
 
         
        for line in lines:
          if status_decision.search(line):
            cols=line.split('::')
            str1=cols[1].lstrip()
            dec=str1.split(' ',1)[0]
            num = int(dec)
            decisions=decisions+num;
          if status_propagation.search(line):
            cols=line.split('::')
            str1=cols[1].lstrip()
            prop=str1.split(' ',1)[0]
            num = int(prop)
            propagations=propagations+num;
          if status_conflict.search(line):
            cols=line.split('::')
            str1=cols[1].lstrip()
            #str2=st1.rstrip()
            con=str1.split(' ',1)[0]
            num = int(con)
            conflicts=conflicts+num
          if status_conflict_literal.search(line):
            cols=line.split('::')
            str1=cols[1].lstrip()
            lit=str1.split(' ',1)[0]
            num = int(lit)
            conflict_literals=conflict_literals+num
          if status_learnt_clauses.search(line):
            cols=line.split('::')
            str1=cols[1].lstrip()
            res=str1.split(' ',1)[0]
            num = int(res)
            learnt_clauses=learnt_clauses+num
          if status_time.search(line):
            cols=line.split(':')
            str1=cols[1].lstrip()
            time=str1.split(' ',1)[0]
        #report.writerow([decisions,propagations,conflicts,conflict_literals,learnt_clauses]) 

        print root, decisions, propagations, conflicts, conflict_literals, learnt_clauses, time 
  
  #report_file=open('statistics.csv', 'wb')
  #report = csv.writer(report_file, delimiter=',',
  #    quotechar='|', quoting=csv.QUOTE_MINIMAL)
  #report.writerow(['decisions', 'propagations', 'conflicts', 'conflict literals', 'learnt clauses']) 
  #report.writerow([decisions,propagations,conflicts,conflict_literals,learnt_clauses]) 
   
processfile()            
