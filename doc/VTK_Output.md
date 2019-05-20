# VTK-Output
## The UnstructuredGrid format (.vtu)
The general format for UnstructuredGrid is:
```
<VTKFile type=”UnstructuredGrid” ...>
  <UnstructuredGrid>
    <Piece NumberOfPoints=”#” NumberOfCells=”#”>
      <PointData>...</PointData>
      <CellData>...</CellData>
      <Points>...</Points>
      <Cells>...</Cells>
    </Piece>
  </UnstructuredGrid>
</VTKFile>
```