defmodule Array do
  def new(ele \\ nil, length \\ 1) do
    Stream.iterate(0, &(&1 + 1))
    |> Stream.zip(Stream.repeatedly(fn -> ele end))
    |> Enum.take(length)
    |> Map.new
    |> Map.put(:length, length)
  end

  def fetch!(array, n) do
    Map.fetch!(array,n)
  end

  def set(array, n, ele) do
    Map.update!(array, n, fn _ -> ele end)
  end

end

defmodule Matrix do
  use Bitwise
  def new(ele \\ nil, i \\ 1, j \\ 1) do
    ele
    |> Array.new(j)
    |> Array.new(i)
  end

  def info(array) do
    row = Map.fetch!(array, :length)
    col = Map.fetch!(array, 0) |> Map.fetch!(:length)
    {row, col}
  end

  def fetchRow!(array, row) do
    array[row]
  end

  def fetch!(array, row, col) do
    array[row][col]
  end

  def set(array, row, col, ele) do
    newRow = array[row] |> Map.update!(col, fn _ -> ele end)
    array |> Map.update!(row, fn _ -> newRow end)
  end

  def eye(n), do: _makeEye(n - 1, new(0,n,n))
  defp _makeEye(-1, ans), do: ans
  defp _makeEye(n, now) do
    _makeEye(n - 1, set(now, n, n, 1))
  end

  def times(a, b) do
    {rowA, colA} = info(a)
    {rowB, colB} = info(b)
    case colA == rowB do
      false -> :error
      true -> _times(a, b, rowA - 1, colB - 1, new(nil, rowA, colB), colB - 1)
    end
  end

  defp getTimesAns(a, b, i, j) do
    {_, colA} = info(a)
    _getTimesAns(a, b, i, j, colA - 1, 0)
  end

  defp _getTimesAns(_, _, _, _, -1, ans), do: ans
  defp _getTimesAns(a, b, i, j, nowP, now) do
    _getTimesAns(a, b, i, j, nowP - 1, now + (a[i][nowP] * b[nowP][j]))
  end

  defp _times(_, _, -1, _, ans, _), do: ans
  defp _times(a, b, nowRow, -1, now, t), do: _times(a, b, nowRow - 1, t, now, t)
  defp _times(a, b, nowRow, nowCol, now, t) do
    ele = getTimesAns(a, b, nowRow, nowCol)
    newMatrix = now |> set(nowRow, nowCol, ele)
    _times(a, b, nowRow, nowCol - 1, newMatrix, t)
  end


  def pow(a, n) do
    {i,j} = info(a)
    case i == j do
      false -> :error
      true -> _pow(a, n, eye(i))
    end
  end

  defp _pow(_a, 0, ans), do: ans
  defp _pow(a, n, now) when band(n, 1) == 1, do: _pow(times(a, a), n >>> 1, times(now, a))
  defp _pow(a, n, now), do: _pow(times(a, a), n >>> 1, now)

end
