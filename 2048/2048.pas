program 2048;
uses crt;

type
  arr = array[0..5,0..5] of longint;
const
  xx : array[1..4] of longint = (0, 0, 1, -1);
  yy : array[1..4] of longint = (-1, 1, 0, 0);
var
  B, b1 : arr;
  p : char;
  score : qword;

procedure left();
var
  l, i, j, x : longint;
begin
  for i := 1 to 4 do begin
      l := 1;
      x := 0;
      j := 1;
      while l<=4 do begin
          if b[i,l]<>0 then begin
              if x=0 then x:=b[i,l]
              else
                if x<>b[i,l] then begin
                    b[i,j]:=x;
                    inc(j);
                    x:=b[i,l];
                end
                else begin
                    b[i,j]:=x*2;
                    inc(score,b[i,j]);
                    inc(j);
                    b[i,j]:=0;
                    x:=0;
                end;
              b[i,l]:=0;
            end;
          inc(l);
      end;
      b[i,j]:=x;
  end;
end;

procedure right();
var
  l,r,i,j,x:longint;
begin
  for i:=1 to 4 do
    begin
      r:=4;
      x:=0;
      j:=4;
      while r>=1 do begin
        if b[i,r]<>0 then begin
          if x=0 then x:=b[i,r]
            else if x<>b[i,r] then begin
              b[i,j]:=x;
              dec(j);
              x:=b[i,r];
              end
              else begin
                b[i,j]:=x*2;
                inc(score,b[i,j]);
                dec(j);
                b[i,j]:=0;
                x:=0;
                end;
          b[i,r]:=0
          end;
        dec(r);
      end;
    b[i,j]:=x;
  end;
end;

procedure down();
var
  d,i,j,x:longint;
begin
  for i:=1 to 4 do
    begin
      d:=4;
      x:=0;
      j:=4;
      while d>=1 do
        begin
          if b[d,i]<>0 then
            begin
              if x=0 then x:=b[d,i]
                else if x<>b[d,i] then
                  begin
                    b[j,iw]:=x;
                    dec(j);
                    x:=b[d,i];
                  end
                       else
                         begin
                           b[j,i]:=x*2;
                           inc(score,b[j,i]);
                           dec(j);
                           b[j,i]:=0;
                           x:=0;
                         end;
              b[d,i]:=0;
            end;
          dec(d);
        end;
      b[j,i]:=x;
    end;
end;

procedure up();
var
  u,i,j,x:longint;
begin
  for i:=1 to 4 do
    begin
     u:=1;
     x:=0;
     j:=1;
     while u<=4 do
       begin
         if b[u,i]<>0 then
           begin
             if x=0 then x:=b[u,i]
               else if x<>b[u,i] then
                 begin
                   b[j,i]:=x;
                   inc(j);
                   x:=b[u,i];
                 end
                 else begin
                   b[j,i]:=x*2;
                   inc(score,b[j,i]);
                   inc(j);
                   b[j,i]:=0;
                   x:=0;
                 end;
             b[u,i]:=0;
           end;
       inc(u);
       end;
    b[j,i]:=x;
    end;
end;

procedure rand();
var
  k1,k2,num:longint;
begin
  randomize;
  k1:=1+random(4);
  k2:=1+random(4);
  num:=1+random(6);
  while B[k1,k2]<>0 do
    begin
      k1:=1+random(4);
      k2:=1+random(4);
    end;
  case num of
  1:B[k1,k2]:=4;
  2,4,3,5,6:B[k1,k2]:=2;
end;
end;

function GameOver():boolean;
var
  i,j,k:longint;
begin
  for i:=1 to 4 do
    for j:=1 to 4 do
      for k:=1 to 4 do
        begin
          if B[i+xx[k],j+yy[k]]=b[i,j] then exit(false);
          if B[i,j]=0 then exit(false);
        end;
      writeln('Game Over');
      exit(true);
end;

procedure writemap();
var
  i,j,k:longint;
begin
  for i:=1 to 4 do
    begin
      writeln('+--------+--------+--------+--------+');
      writeln('|||||');
      for j:=1 to 4 do
      if j=1 then
        begin
          if b[i,j]<>0 then
            begin
              write('|');
              case b[i,j] of
              2:textcolor(lightgray);
              8:textcolor(green);
              16:textcolor(lightgreen);
              32:textcolor(yellow);
              64:textcolor(lightmagenta);
              128:textcolor(red);
              256:textcolor(lightred);
              512:textcolor(yellow);
              1024:textcolor(lightmagenta);
              2048:textcolor(cyan);
              4096:textcolor(lightcyan);
            end;
          write(b[i,j]:5);
          textcolor(white);
        end
      else write('|','':5);
    end
  else
    begin
      if b[i,j]<>0 then
        begin
          write('|');
          case b[i,j] of
          2:textcolor(lightgray);
          8:textcolor(green);
          16:textcolor(lightgreen);
          32:textcolor(yellow);
          64:textcolor(lightmagenta);
          128:textcolor(red);
          256:textcolor(lightred);
          512:textcolor(yellow);
          1024:textcolor(lightmagenta);
          2048:textcolor(cyan);
          4096:textcolor(lightcyan);
        end;
      write(b[i,j]:5);
      textcolor(white);
    end
    else write('|','':5);
  end;
    writeln('|');
    writeln('|||||');
  end;
    writeln('+--------+--------+--------+--------+');
    writeln('score:',score);
end;

procedure init();
begin
  rand();
  rand();
  score:=0;
end;

procedure makeit(command :char);
var
  i:longint;
begin
  case command of
    'w':up();
    'a':left();
    's':down();
    'd':right();
    'z':halt;
  end;
end;

function change():boolean;
var
  i,j:longint;
begin
  for i:=1 to 4 do
    for j:=1 to 4 do
      if b1[i,j]<>b[i,j] then exit(true);
        exit(false);
end;

begin
  init();
  repeat
  clrscr;
  writemap();
  p := readkey;
  while(p <> 'w') and (p <> 'a') and (p<>'s') and (p<>'d') and (p<>'z') do p:=readkey;
  b1:=b;
  makeit(p);
  if change then rand();
  until false;
  readln;
  readln;
  readln;
  readln;
end.